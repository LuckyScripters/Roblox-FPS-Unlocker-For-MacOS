#include <string>
#include <fstream>
#include <iostream>

#include <sys/stat.h>

using namespace std;

int fpsCaps = 10000;
string separator = ", ";

void addClientSettings()
{
    string answer;
    const char* clientSettingsPath = "/Applications/Roblox.app/Contents/MacOS/ClientSettings";
    const string clientAppSettingsPath = "/Applications/Roblox.app/Contents/MacOS/ClientSettings/ClientAppSettings.json";
    cout << "Do you want to use Vulkan? Answer yes or no." << endl;
    getline(cin, answer);
    if (answer == "yes")
    {
        int directoryCreationStatus = mkdir(clientSettingsPath, S_IRUSR | S_IWUSR | S_IXUSR);
        if (directoryCreationStatus == 0)
        {
            cout << "File has been created" << endl;
        }
        else
        {
            cout << "Failed to create file: " << strerror(errno) << endl;
            exit(-1);
        }
        ofstream clientAppSettings(clientAppSettingsPath);
        clientAppSettings << R"({"DFIntTaskSchedulerTargetFps": )" + to_string(fpsCaps) << separator << R"("FFlagDebugGraphicsDisableMetal": true)" << separator << R"("FFlagDebugGraphicsPreferVulkan": true)" << "}" << endl;
        clientAppSettings.close();
        cout << "Successfully set fpsCaps to " + to_string(fpsCaps) + " with Vulkan mode" << endl;
    }
    else if (answer == "no")
    {
        int directoryCreationStatus = mkdir(clientSettingsPath, S_IRUSR | S_IWUSR | S_IXUSR);
        if (directoryCreationStatus == 0)
        {
            cout << "File has been created" << endl;
        }
        else
        {
            cout << "Failed to create file: " << strerror(errno) << endl;
            exit(-1);
        }
        ofstream clientAppSettings(clientAppSettingsPath);
        clientAppSettings << R"({"DFIntTaskSchedulerTargetFps": )" + to_string(fpsCaps) << "}" << endl;
        clientAppSettings.close();
        cout << "Successfully set fpsCaps to " + to_string(fpsCaps) << endl;
    }
    else
    {
        cout << "Invalid answer" << endl;
        exit(-1);
    }
}

int main(int argc, const char* argv[]) {
    string answer;
    cout << "Do you want to create ClientSettings? Answer create" << endl;
    getline(cin, answer);
    if (answer == "create")
    {
        addClientSettings();
    }
    else
    {
        cout << "Invalid Answer" << endl;
    }
    return 0;
}
