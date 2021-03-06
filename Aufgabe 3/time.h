/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef time_H
#define time_H

#include <thrift/TDispatchProcessor.h>
#include "your_thrift_file_types.h"

#include <iostream>
#include <ctime>
#include <time.h>
#include <string.h>
#include <sstream>
using namespace std;

namespace Test {

class timeIf {
 public:
  virtual ~timeIf() {}
  virtual int32_t ping() = 0;
  virtual void ZeitausgabeS(std::string& _return) = 0;
  virtual void ZeitausgabeU(std::string& _return) = 0;
};

class timeIfFactory {
 public:
  typedef timeIf Handler;

  virtual ~timeIfFactory() {}

  virtual timeIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(timeIf* /* handler */) = 0;
};

class timeIfSingletonFactory : virtual public timeIfFactory {
 public:
  timeIfSingletonFactory(const boost::shared_ptr<timeIf>& iface) : iface_(iface) {}
  virtual ~timeIfSingletonFactory() {}

  virtual timeIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(timeIf* /* handler */) {}

 protected:
  boost::shared_ptr<timeIf> iface_;
};

class timeNull : virtual public timeIf {
 public:
  virtual ~timeNull() {}
  int32_t ping() {
    int32_t _return = 0;
    return _return;
  }
  void ZeitausgabeS(std::string& /* _return */) {
    return;
  }
  void ZeitausgabeU(std::string& /* _return */) {
    return;
  }
};


class time_ping_args {
 public:

  time_ping_args() {
  }

  virtual ~time_ping_args() throw() {}


  bool operator == (const time_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const time_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const time_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class time_ping_pargs {
 public:


  virtual ~time_ping_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _time_ping_result__isset {
  _time_ping_result__isset() : success(false) {}
  bool success;
} _time_ping_result__isset;

class time_ping_result {
 public:

  time_ping_result() : success(0) {
  }

  virtual ~time_ping_result() throw() {}

  int32_t success;

  _time_ping_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const time_ping_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const time_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const time_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _time_ping_presult__isset {
  _time_ping_presult__isset() : success(false) {}
  bool success;
} _time_ping_presult__isset;

class time_ping_presult {
 public:


  virtual ~time_ping_presult() throw() {}

  int32_t* success;

  _time_ping_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class time_ZeitausgabeS_args {
 public:

  time_ZeitausgabeS_args() {
  }

  virtual ~time_ZeitausgabeS_args() throw() {}


  bool operator == (const time_ZeitausgabeS_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const time_ZeitausgabeS_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const time_ZeitausgabeS_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class time_ZeitausgabeS_pargs {
 public:


  virtual ~time_ZeitausgabeS_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _time_ZeitausgabeS_result__isset {
  _time_ZeitausgabeS_result__isset() : success(false) {}
  bool success;
} _time_ZeitausgabeS_result__isset;

class time_ZeitausgabeS_result {
 public:

  time_ZeitausgabeS_result() : success() {
  }

  virtual ~time_ZeitausgabeS_result() throw() {}

  std::string success;

  _time_ZeitausgabeS_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const time_ZeitausgabeS_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const time_ZeitausgabeS_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const time_ZeitausgabeS_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _time_ZeitausgabeS_presult__isset {
  _time_ZeitausgabeS_presult__isset() : success(false) {}
  bool success;
} _time_ZeitausgabeS_presult__isset;

class time_ZeitausgabeS_presult {
 public:


  virtual ~time_ZeitausgabeS_presult() throw() {}

  std::string* success;

  _time_ZeitausgabeS_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class time_ZeitausgabeU_args {
 public:

  time_ZeitausgabeU_args() {
  }

  virtual ~time_ZeitausgabeU_args() throw() {}


  bool operator == (const time_ZeitausgabeU_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const time_ZeitausgabeU_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const time_ZeitausgabeU_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class time_ZeitausgabeU_pargs {
 public:


  virtual ~time_ZeitausgabeU_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _time_ZeitausgabeU_result__isset {
  _time_ZeitausgabeU_result__isset() : success(false) {}
  bool success;
} _time_ZeitausgabeU_result__isset;

class time_ZeitausgabeU_result {
 public:

  time_ZeitausgabeU_result() : success() {
  }

  virtual ~time_ZeitausgabeU_result() throw() {}

  std::string success;

  _time_ZeitausgabeU_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const time_ZeitausgabeU_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const time_ZeitausgabeU_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const time_ZeitausgabeU_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _time_ZeitausgabeU_presult__isset {
  _time_ZeitausgabeU_presult__isset() : success(false) {}
  bool success;
} _time_ZeitausgabeU_presult__isset;

class time_ZeitausgabeU_presult {
 public:


  virtual ~time_ZeitausgabeU_presult() throw() {}

  std::string* success;

  _time_ZeitausgabeU_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class timeClient : virtual public timeIf {
 public:
  timeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  timeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t ping();
  void send_ping();
  int32_t recv_ping();
  void ZeitausgabeS(std::string& _return);
  void send_ZeitausgabeS();
  void recv_ZeitausgabeS(std::string& _return);
  void ZeitausgabeU(std::string& _return);
  void send_ZeitausgabeU();
  void recv_ZeitausgabeU(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class timeProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<timeIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (timeProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ZeitausgabeS(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_ZeitausgabeU(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  timeProcessor(boost::shared_ptr<timeIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &timeProcessor::process_ping;
    processMap_["ZeitausgabeS"] = &timeProcessor::process_ZeitausgabeS;
    processMap_["ZeitausgabeU"] = &timeProcessor::process_ZeitausgabeU;
  }

  virtual ~timeProcessor() {}
};

class timeProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  timeProcessorFactory(const ::boost::shared_ptr< timeIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< timeIfFactory > handlerFactory_;
};

class timeMultiface : virtual public timeIf {
 public:
  timeMultiface(std::vector<boost::shared_ptr<timeIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~timeMultiface() {}
 protected:
  std::vector<boost::shared_ptr<timeIf> > ifaces_;
  timeMultiface() {}
  void add(boost::shared_ptr<timeIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping();
    }
    return ifaces_[i]->ping();
  }

  void ZeitausgabeS(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ZeitausgabeS(_return);
    }
    ifaces_[i]->ZeitausgabeS(_return);
    return;
  }

  void ZeitausgabeU(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ZeitausgabeU(_return);
    }
    ifaces_[i]->ZeitausgabeU(_return);
    return;
  }

};

} // namespace

#endif
