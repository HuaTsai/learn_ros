#include <ros/ros.h>
#include <pcl_ros/io/pcd_io.h>
#include <Eigen/Dense>
#include <pcl_ros/transforms.h>
#include <pcl/registration/ndt.h>
#include <tf/tf.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "ndt");
  ros::NodeHandle nh;
  ros::Rate rate(0.5);
  if (argc != 3) {
    ROS_FATAL("usage: rosrun pcl_ros_test ndt <pcd_source> <pcd_target>");
    return -1;
  }
  pcl::PointCloud<pcl::PointXYZ>::Ptr source_pc(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr target_pc(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *source_pc);
  pcl::io::loadPCDFile<pcl::PointXYZ>(argv[2], *target_pc);
  ROS_INFO("Loaded %ld data points from %s", source_pc->size(), argv[1]);
  ROS_INFO("Loaded %ld data points from %s", target_pc->size(), argv[2]);

  /*pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::ApproximateVoxelGrid<pcl::PointXYZ> approximate_voxel_filter;
  approximate_voxel_filter.setLeafSize (0.2, 0.2, 0.2);
  approximate_voxel_filter.setInputCloud (input_pc);
  approximate_voxel_filter.filter (*filtered_cloud);
  std::cout << "Filtered cloud contains " << filtered_cloud->size ()
            << " data points from room_scan2.pcd" << std::endl;*/

  // init guess 23~24
  tf::Transform tr1(tf::Quaternion(-0.0194076, -0.0479432, 0.000980381, 0.998661), tf::Vector3(47.9432, 4.58133, 4.54288));
  tf::Transform tr2(tf::Quaternion(-0.0193538, -0.0461148, 0.0143876, 0.998645), tf::Vector3(50.9634, 4.79877, 4.82314));
  tf::Transform tr3 = tr1.inverse() * tr2;
  Eigen::Matrix4f guess;
  pcl_ros::transformAsMatrix(tr3, guess);
  geometry_msgs::Vector3 v3;
  geometry_msgs::Quaternion q3;
  tf::vector3TFToMsg(tr3.getOrigin(), v3);
  tf::Matrix3x3 m3(tr3.getRotation());
  double r, p, y;
  m3.getRPY(r, p, y);
  bool run = true;
  float eps = 0.01, step_size = 0.05, res = 1.0;
  int max_iter = 35;

  while(1) {    
    if (nh.hasParam("epislon")) {
      float eps_temp, step_size_temp, res_temp;
      int max_iter_temp;
      nh.getParam("epislon", eps_temp);
      nh.getParam("step_size", step_size_temp);
      nh.getParam("resolution", res_temp);
      nh.getParam("max_iter", max_iter_temp);
      if (eps_temp != eps || step_size_temp != step_size ||
          res_temp != res || max_iter_temp != max_iter) {
        eps = eps_temp;
        step_size = step_size_temp;
        res = res_temp;
        max_iter = max_iter_temp;
        run = true;
        std::cout << eps << ", " << step_size << ", " << res << ", " << max_iter << std::endl;
      }
    }
    if (run) {
      pcl::NormalDistributionsTransform<pcl::PointXYZ, pcl::PointXYZ> ndt;
      ndt.setTransformationEpsilon(eps);
      ndt.setStepSize(step_size);
      ndt.setResolution(res);
      ndt.setMaximumIterations(max_iter);

      ndt.setInputSource(source_pc);
      ndt.setInputTarget(target_pc);

      pcl::PointCloud<pcl::PointXYZ>::Ptr output_pc (new pcl::PointCloud<pcl::PointXYZ>);
      
      ROS_INFO("%ld", output_pc->size());
      std::cout << "ndt has converged:" << std::boolalpha << ndt.hasConverged()
                << " score: " << ndt.getFitnessScore()
                << ", iters: " << ndt.getFinalNumIteration() << std::endl;

      pcl::transformPointCloud(*source_pc, *output_pc, ndt.getFinalTransformation());
      Eigen::Matrix4f m = ndt.getFinalTransformation();
      m3 = tf::Matrix3x3(m(0,0), m(0,1), m(0,2), m(1,0), m(1,1), m(1,2), m(2,0), m(2,1), m(2,2));
      double r2, p2, y2;
      m3.getRPY(r2, p2, y2);

      ROS_INFO("guess: %f, %f, %f, %f, %f, %f", v3.x, v3.y, v3.z, r, p, y);
      ROS_INFO("ndt: %f, %f, %f, %f, %f, %f", m(0,3), m(1,3), m(2,3), r2, p2, y2);
      run = false;
    }
    rate.sleep();
  }
}