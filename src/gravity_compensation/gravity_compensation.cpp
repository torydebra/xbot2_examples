#include "gravity_compensation.h"

bool GravityCompensation::on_initialize()
{

    //_robot->setControlMode(ControlMode::Position());

    return true;
}

void GravityCompensation::starting()
{
    
    gravity_vector << 0, 0, 9.8; 
    // do some on-start initialization
    _robot->sense();


     std::string path_to_config_file = XBot::Utils::getXBotConfig();
     auto model = XBot::ModelInterface::getModel(path_to_config_file);
    
     model->computeGravityCompensation(gravity_vector);
    // we can switch to run
    start_completed();
}

void GravityCompensation::run()
{
    _robot->sense(false);
    
    //TRIALS
    std::string path_to_config_file = XBot::Utils::getXBotConfig();
    auto robot = XBot::RobotInterface::getRobot(path_to_config_file);
    
    Eigen::VectorXd q_actual;
    q_actual[0] = 0.1;
    robot->getJointPosition(q_actual);
    robot->setPositionReference(q_actual*1.1);
     
     
     
    //_robot->computeGravityCompensation (gravity_vector);
}

XBOT2_REGISTER_PLUGIN(GravityCompensation, gravity_compensation)
