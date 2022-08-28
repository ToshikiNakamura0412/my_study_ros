#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/TransformStamped.h>

std::tuple<int, int>get_test_tuple()
{
    return std::make_tuple(4, 100);
}

void map_callback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
    std::cout << "subscribe a map!" << std::endl;
}

void sort_data(std::vector<double>& data)
{
    double tmp;
    for(int i=0; i<data.size()-1; i++)
    {
        for(int j=i+1; j<data.size(); j++)
        {
            if(data[i] > data[j])
            {
                tmp     = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}

double get_median(std::vector<double>& data)
{
    sort_data(data);
    if(data.size()%2 == 1)
        return data[(data.size()-1) / 2];
    else
        return (data[data.size()/2 - 1] + data[data.size()/2]) / 2.0;
}

struct positon
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

class Pose
{
public:
    Pose(const double x, const double y){
        x_=x; y_=y;
    }
    void show(){
        std::cout << "x=" << x_ << ", y=" << y_ << std::endl;
    }
private:
    double x_;
    double y_;
};


int main(int argc, char* argv[])
{
    // ===== ROS =====
    // ----- STREAM -----
    // ROS_INFO_STREAM("INFO");
    // ROS_WARN_STREAM("WARN");
    // ROS_ERROR_STREAM("ERROR");
    // ROS_INFO_STREAM("INFO");

    // ----- INFO_STREAM -----
    // int a = 1;
    // double b = 2.0;
    // ROS_INFO_STREAM("a: " << a << ", b: " <<  b);

    // ----- getParam -----
    // ros::init(argc, argv, "my_study_ros");
    // ros::NodeHandle nh;
    // int num = 0;
    // ROS_INFO_STREAM(num);
    // nh.getParam("test_num1", num);
    // ROS_INFO_STREAM(num);
    // nh.getParam("test_num2", num);
    // ROS_INFO_STREAM(num);
    // ROS_INFO_STREAM(floor(3.14));

    // ----- publish PointStamped -----
    // ros::init(argc, argv, "my_study_ros");
    // ros::NodeHandle nh;
    // ros::Publisher pub_point;
    // pub_point = nh.advertise<geometry_msgs::PointStamped>("/test_point",1);
    // geometry_msgs::PointStamped point;
    // point.header.frame_id = "map";
    // point.point.x = 11.5;
    // point.point.y = 10.0;
    // while(ros::ok())
    // {
    //     pub_point.publish(point);
    // }

    // ----- std_msgs -----
    // std_msgs::Bool flag_test_;
    // flag_test_.data = false;
    // ROS_INFO_STREAM(flag_test_);

    // ----- PoseStamped -----
    // geometry_msgs::PoseStamped pose_stamped_test;
    // ROS_INFO_STREAM("<< PoseStamped >>");
    // ROS_INFO_STREAM(pose_stamped_test);

    // ----- TransformStamped -----
    // geometry_msgs::TransformStamped transform_stamped_test;
    // ROS_INFO_STREAM("<< TransformStamped >>");
    // ROS_INFO_STREAM(transform_stamped_test);

    // ----- spinOnce -----
    // ros::init(argc, argv, "my_study_ros");
    // ros::NodeHandle nh;
    // ros::Subscriber sub_map;
    // sub_map = nh.subscribe("/map", 1, &map_callback);
    // while(ros::ok())
    // {
    //     ros::spinOnce();
    //     std::cout << "[Test] spinOnce" << std::endl;
    //     ros::Duration(1).sleep();
    // }


    // ===== C++ vector =====
    // ----- push_back(多次元配列) -----
    // std::vector<std::vector<int>> matrix;
    // std::vector<int> point{10,20};
    // for(int i=0; i<3; i++) matrix.push_back(point);
    // std::cout << "\nsize: " << matrix.size() << std::endl;
    // for(int i=0; i<matrix.size(); i++)
    // {
    //     std::cout << "i:" << i << " {";
    //     for(int j=0; j<matrix[i].size(); j++)
    //     {
    //         std::cout << matrix[i][j];
    //         if(j != matrix[i].size()-1)
    //             std::cout << ", ";
    //         else
    //             std::cout << "}" << std::endl;
    //     }
    // }

    // ----- insert -----
    // std::vector<int> insert_test_vector;
    // std::vector<int> point{1,2,3,4,5};
    // for(int i=0; i<3; i++) insert_test_vector.insert(insert_test_vector.end(), point.begin(), point.end());
    // std::cout << "{";
    // for(int i=0; i<insert_test_vector.size(); i++)
    // {
    //     std::cout << insert_test_vector[i];
    //     if(i != insert_test_vector.size()-1)
    //         std::cout << ", ";
    //     else
    //         std::cout << "}" << std::endl;
    // }

    // ----- erase -----
    // std::vector<int> erase_test_vector;
    // for(int i=0; i<5; i++) erase_test_vector.push_back(i);
    // for(int i=0; i<erase_test_vector.size(); i++) std::cout << erase_test_vector[i] << std::endl;
    // std::cout << "<< erase >>" << std::endl;
    // erase_test_vector.erase(erase_test_vector.begin()+3);
    // for(int i=0; i<erase_test_vector.size(); i++) std::cout << erase_test_vector[i] << std::endl;

    // ----- reverse -----
    // std::vector<int> reverse_test_vector;
    // for(int i=0; i<5; i++) reverse_test_vector.push_back(i);
    // for(int i=0; i<reverse_test_vector.size(); i++) std::cout << reverse_test_vector[i] << std::endl;
    // std::cout << "<< reverse >>" << std::endl;
    // reverse(reverse_test_vector.begin(), reverse_test_vector.end());
    // for(int i=0; i<reverse_test_vector.size(); i++) std::cout << reverse_test_vector[i] << std::endl;

    // ----- duplicate -----
    // std::vector<int> origin;
    // for(int i=0; i<10; i++) origin.push_back(i);
    // std::cout << "origin" << std::endl;
    // for(int i=0; i<origin.size(); i++) std::cout << "[" << i << "]: " << origin[i] << std::endl;
    // std::vector<int> copy(origin);
    // std::cout << "copy" << std::endl;
    // for(int i=0; i<copy.size(); i++) std::cout << "[" << i << "]: " << copy[i] << std::endl;

    // ----- sort -----
    // std::vector<double> data;
    // for(double i=10.0; i>0.0; i--) data.push_back(i);
    // for(int i=0; i<data.size(); i++) std::cout << "[" << i << "]: " << data[i] << std::endl;
    // sort_data(data);
    // std::cout << "sort data" << std::endl;
    // for(int i=0; i<data.size(); i++) std::cout << "[" << i << "]: " << data[i] << std::endl;
    // std::cout << "median: " << get_median(data) << std::endl;


    // ===== C++ other =====
    // ----- tuple -----
    // int a, b;
    // std::cout << "a: " << a << ", b: " << b << std::endl;
    // std::tie(a, b) = get_test_tuple();
    // std::cout << "a: " << a << ", b: " << b << std::endl;

    // ----- pow -----
    // double a = 2.0;
    // std::cout << "pow(2.0,3.0)=" << pow(a,3.0) << std::endl;
    // std::cout << "type: " << typeid(pow(a,3.0)).name() << std::endl;

    // ----- operator -----
    // operator= いらない?
    // コンパイル時に生成されるものはいらない
    // Pose pose1(1,2);
    // Pose pose2(1,2);
    // std::cout << "pose1" << std::endl;
    // pose1.show();
    // pose1 = Pose(3,4);
    // std::cout << "代入" << std::endl;
    // pose1.show();
    // pose1 = pose2;
    // std::cout << "代入" << std::endl;
    // pose1.show();

    // ----- rand -----
    // std::cout << "RAND_MAX: " << RAND_MAX << std::endl;
    // for(int i=0; i<10; i++)
    //         std::cout << "rand" << i << ": " << (double)rand()/(RAND_MAX * 10.0) << std::endl;

    // ----- struct -----
    // positon position1;
    // positon position2;
    // position2.x = 10.0;
    // position2.y = 20.0;
    // position2.z = 30.0;
    // std::cout <<"position1" << std::endl;
    // std::cout <<"x: " << position1.x << std::endl;
    // std::cout <<"y: " << position1.y << std::endl;
    // std::cout <<"z: " << position1.z << std::endl;
    // position1 = position2;
    // std::cout <<"position1" << std::endl;
    // std::cout <<"x: " << position1.x << std::endl;
    // std::cout <<"y: " << position1.y << std::endl;
    // std::cout <<"z: " << position1.z << std::endl;

    return 0;
}
