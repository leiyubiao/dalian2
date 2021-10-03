#include "data.h"

namespace data_space
{

    json ReadJson()
    {
        // string tmp;
        // tmp = get_current_dir_name();
        // string json_path = tmp + "/src/lqr_controller/config/params.json";
        // /home/sjtuzq/flm_ws/src/tracking/adas/config/params.json
        string json_path = "/home/sjtuzq/flm_ws/src/tracking/adas/config/params.json";
        ifstream json_file(json_path);
        json param;
        json_file >> param;
        return param;
    }

    json params_json = ReadJson();
}