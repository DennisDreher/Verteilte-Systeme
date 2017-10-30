#include "time.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace Test;

int main(int argc, char **argv) {
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 12345));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  struct tm *newtime;
  time_t currenttime;
  time(&currenttime);
  newtime = localtime(&currenttime);
  time_t anfangszeit = time(0);

  string testzeitS;
  string testzeitU;

  timeClient client(protocol);
  transport->open();
  client.ZeitausgabeS(testzeitS);
  client.ZeitausgabeU(testzeitU);
  transport->close();

  

  cout << testzeitS << endl << testzeitU << endl;

  time(&currenttime);
  newtime = localtime(&currenttime);
  time_t endzeit = time(0);
  time_t gesamt = endzeit - anfangszeit;
  cout << gesamt << endl;

  return 0;
}
