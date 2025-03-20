#include <ur_rtde/rtde_control_interface.h>
#include <ur_rtde/rtde_receive_interface.h>

#include <thread>
#include <chrono>

using namespace ur_rtde;
using namespace std::chrono;

//interrupt flag
bool running = true;
void raiseFlag(int param)
{
  running = false;
}


int main(int argc,char* argv[])
{
    std::string robot_ip = "localhost";
    double rtde_frequency = 500.0; // Hz
    double dt = 1.0 / rtde_frequency; // 2ms
    uint16_t flags = RTDEControlInterface::FLAG_VERBOSE | RTDEControlInterface::FLAG_UPLOAD_SCRIPT;
    int ur_cap_port = 50002;
  
    // ur_rtde realtime priorities
    int rt_receive_priority = 90;
    int rt_control_priority = 85;
  
    RTDEControlInterface rtde_control(robot_ip, rtde_frequency, flags, ur_cap_port, rt_control_priority);
    RTDEReceiveInterface rtde_receive(robot_ip, rtde_frequency, {}, true, false, rt_receive_priority);

    // Set application realtime priority
    RTDEUtility::setRealtimePriority(80);

    std::vector<double> current_q = rtde_receive.getActualQ();

    // Move parameters
    double vel = 0.5;
    double acc = 0.5;

    // Servo control parameters
    double lookahead_time = 0.1;
    double gain = 600;

    signal(SIGINT, raiseFlag);

    double time_counter = 0.0;

    for(int i =1;i<=1000;i++)
    {
        steady_clock::time_point t_start = rtde_control.initPeriod();
        rtde_control.servoJ(current_q,vel, acc, dt, lookahead_time, gain);
        current_q[1] = current_q[1] + 0.01*(-3.14/180);
        rtde_control.waitPeriod(t_start);
        std::cout << current_q[1] << std::endl;
    }
}