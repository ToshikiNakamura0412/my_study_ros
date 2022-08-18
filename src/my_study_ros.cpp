#include <ros/ros.h>

std::tuple<int, int>get_test_tuple()
{
    return std::make_tuple(4, 100);
}

int main(int argc, char* argv[])
{
    // ===== ROS =====
    // ----- STREAM -----
    // ROS_INFO_STREAM("INFO");
    // ROS_WARN_STREAM("WARN");
    // ROS_ERROR_STREAM("ERROR");
    // ROS_INFO_STREAM("INFO");

    // ----- getParam -----
    // ros::init(argc, argv, "my_study_ros");
    // ros::NodeHandle nh_;
    // int num = 0;
    // ROS_INFO_STREAM(num);
    // nh_.getParam("test_num1", num);
    // ROS_INFO_STREAM(num);
    // nh_.getParam("test_num2", num);
    // ROS_INFO_STREAM(num);
    // ROS_INFO_STREAM(floor(3.14));


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


    // ===== C++ other =====
    // ----- tuple -----
    // int a, b;
    // std::cout << "a: " << a << ", b: " << b << std::endl;
    // std::tie(a, b) = get_test_tuple();
    // std::cout << "a: " << a << ", b: " << b << std::endl;

    return 0;
}
