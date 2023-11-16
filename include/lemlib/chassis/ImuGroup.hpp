#include "main.h"
namespace lemlib {
class ImuGroup {
    private:
        std::vector<pros::Imu*> imuList;
        std::vector<float> errorMultiplierList;

    public:
        ImuGroup(std::vector<pros::Imu*>);
        ImuGroup(std::vector<pros::Imu*>, std::vector<float>);
        float get_rotation();
        float get_rotation(int);
        float get_raw_rotation();
        float get_raw_rotation(int);
        std::int32_t reset(bool);
};
}


