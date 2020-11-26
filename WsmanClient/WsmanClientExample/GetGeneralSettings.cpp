// SPDX: Apache-2.0

#include <iostream>
#include <memory>
#include <CimOpenWsmanClient.h>
#include <AMT_GeneralSettings.h>

using namespace std;
using namespace WsmanClientNamespace;

using namespace Intel::Manageability::Exceptions;
using namespace Intel::Manageability::Cim::Typed;
using namespace Intel::WSManagement;

int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: " << argv[0] << " host user password" << endl;
        exit(1);
    }

    string host = string(argv[1]);
    string user = string(argv[2]);
    string password = string(argv[3]);

    CimOpenWsmanClient *wsclient = new CimOpenWsmanClient(host, 16992, false, DIGEST, user, password);
    AMT_GeneralSettings genset(wsclient);
    genset.Get();
    cout << "Network interface enabled  : " << genset.NetworkInterfaceEnabled() << endl;
    cout << "Digest Realm               : " << genset.DigestRealm() << endl;
    cout << "IdleWakeTimeout            : " << genset.IdleWakeTimeout() << endl;
    cout << "AMT Hostname               : " << genset.HostName() << endl;
    cout << "Domain Name                : " << genset.DomainName() << endl;
    cout << "Ping Response enabled      : " << genset.PingResponseEnabled() << endl;
    cout << "Wsman Only Mode            : " << genset.WsmanOnlyMode() << endl;
    cout << "Preferred Address family   : " << genset.PreferredAddressFamily() << endl;
    return 0;
}
