#ifndef GRAVITY_COMPENSATION_H
#define GRAVITY_COMPENSATION_H

// main XBot2 include
#include <xbot2/xbot2.h>

using namespace XBot;

/**
 * @brief The HomingExample class is a ControlPlugin
 * implementing a simple homing motion.
 */
class GravityCompensation : public ControlPlugin
{

public:

    // we don't do anything special inside the
    // constructor, so just inherit the base class
    // implementation
    using ControlPlugin::ControlPlugin;

    // initialization method; the plugin won't be run
    // if this returns 'false'
    bool on_initialize() override;

    // callback for the 'Starting' state
    // start_completed() must be called to switch
    // to 'Run' state
    void starting() override;

    // callback for 'Run' state
    void run() override;

private:

    Eigen::VectorXd _q_start;
    Eigen::VectorXd gravity_vector;
    //double _homing_time;
    //double _fake_time;

};

#endif // GRAVITY_COMPENSATION_H
