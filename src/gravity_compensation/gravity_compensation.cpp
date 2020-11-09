#include "gravity_compensation.h"
#include <XBotInterface/SoLib.h>

bool GravityCompensation::on_initialize()
{

    //_robot->setControlMode(ControlMode::Position());

    return true;
}

void GravityCompensation::starting()
{
    gravity_vector.resize(3);
    gravity_vector << 0, 0, 9.8; 
    // do some on-start initialization
    _robot->sense();
    
    _robot->setControlMode(ControlMode::Idle());


    std::string path_to_config_file = XBot::Utils::getXBotConfig();
    model = XBot::ModelInterface::getModel(path_to_config_file);

    //model->computeGravityCompensation(gravity_vector);

    // we can switch to run
    start_completed();

}

void GravityCompensation::run()
{

    _robot->sense(false);
    
    //TRIALS
//     std::string path_to_config_file = XBot::Utils::getXBotConfig();
//                 std::cout << path_to_config_file<< std::endl;
//                 
//     std::cout << "ddddddddddddddddddddd"<< std::endl;
//     
//     
//     auto robot = XBot::RobotInterface::getRobot(path_to_config_file);
//     
//     std::cout << "fffffffffffffffff"<< std::endl;
// 
// 
     Eigen::VectorXd q_actual;    
     _robot->getJointPosition(q_actual);

    //Eigen::Vector3d grav;
   // model->getGravity(grav);
   // std::cout << "GRAAAAAAAAAAAAAv: " << grav << std::endl;
     
    model->setJointPosition(q_actual);
    Eigen::VectorXd gravity_torque;
    model->computeGravityCompensation(gravity_torque);
    std::cout << gravity_torque << std::endl;
    model->setJointEffort(gravity_torque*0.1);

    model->update();
        _robot->setControlMode(ControlMode::Idle());

    //_robot->setReferenceFrom(*model);
    //_robot->move();

       
    //_robot->computeGravityCompensation (gravity_vector);
}

XBOT2_REGISTER_PLUGIN(GravityCompensation, gravity_compensation)
