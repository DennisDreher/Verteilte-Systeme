/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef lamport_H
#define lamport_H

#include <thrift/TDispatchProcessor.h>
#include "your_thrift_file_types.h"

#include <iostream>
#include <string>

#define SOCKET1		boost::shared_ptr<TSocket> socket1(new TSocket("localhost", 9091))
#define TRANSPORT1	boost::shared_ptr<TTransport> transport1(new TBufferedTransport(socket1))
#define PROTOCOL1	boost::shared_ptr<TProtocol> protocol1(new TBinaryProtocol(transport1))
#define CLIENT1		lamportClient client1(protocol1)

#define SOCKET2		boost::shared_ptr<TSocket> socket2(new TSocket("localhost", 9092))
#define TRANSPORT2	boost::shared_ptr<TTransport> transport2(new TBufferedTransport(socket2))
#define PROTOCOL2	boost::shared_ptr<TProtocol> protocol2(new TBinaryProtocol(transport2))
#define CLIENT2		lamportClient client2(protocol2)

#define SOCKET3		boost::shared_ptr<TSocket> socket3(new TSocket("localhost", 9093))
#define TRANSPORT3	boost::shared_ptr<TTransport> transport3(new TBufferedTransport(socket3))
#define PROTOCOL3	boost::shared_ptr<TProtocol> protocol3(new TBinaryProtocol(transport3))
#define CLIENT3		lamportClient client3(protocol3)

#define	MY_CLIENT	2
#define MY_SERVER	2

namespace Test {

class lamportIf {
 public:
  virtual ~lamportIf() {}
  virtual void lock() = 0;
  virtual void unlock() = 0;
  virtual int32_t request(const int32_t ts, const int32_t wclient) = 0;
  virtual void release(const int32_t ts) = 0;
  virtual void servercommunication() = 0;
};

class lamportIfFactory {
 public:
  typedef lamportIf Handler;

  virtual ~lamportIfFactory() {}

  virtual lamportIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(lamportIf* /* handler */) = 0;
};

class lamportIfSingletonFactory : virtual public lamportIfFactory {
 public:
  lamportIfSingletonFactory(const boost::shared_ptr<lamportIf>& iface) : iface_(iface) {}
  virtual ~lamportIfSingletonFactory() {}

  virtual lamportIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(lamportIf* /* handler */) {}

 protected:
  boost::shared_ptr<lamportIf> iface_;
};

class lamportNull : virtual public lamportIf {
 public:
  virtual ~lamportNull() {}
  void lock() {
    return;
  }
  void unlock() {
    return;
  }
  int32_t request(const int32_t /* ts */, const int32_t /* wclient */) {
    int32_t _return = 0;
    return _return;
  }
  void release(const int32_t /* ts */) {
    return;
  }
  void servercommunication() {
    return;
  }
};


class lamport_lock_args {
 public:

  lamport_lock_args() {
  }

  virtual ~lamport_lock_args() throw() {}


  bool operator == (const lamport_lock_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const lamport_lock_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_lock_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_lock_pargs {
 public:


  virtual ~lamport_lock_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_lock_result {
 public:

  lamport_lock_result() {
  }

  virtual ~lamport_lock_result() throw() {}


  bool operator == (const lamport_lock_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const lamport_lock_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_lock_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_lock_presult {
 public:


  virtual ~lamport_lock_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class lamport_unlock_args {
 public:

  lamport_unlock_args() {
  }

  virtual ~lamport_unlock_args() throw() {}


  bool operator == (const lamport_unlock_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const lamport_unlock_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_unlock_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_unlock_pargs {
 public:


  virtual ~lamport_unlock_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_unlock_result {
 public:

  lamport_unlock_result() {
  }

  virtual ~lamport_unlock_result() throw() {}


  bool operator == (const lamport_unlock_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const lamport_unlock_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_unlock_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_unlock_presult {
 public:


  virtual ~lamport_unlock_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _lamport_request_args__isset {
  _lamport_request_args__isset() : ts(false), wclient(false) {}
  bool ts;
  bool wclient;
} _lamport_request_args__isset;

class lamport_request_args {
 public:

  lamport_request_args() : ts(0), wclient(0) {
  }

  virtual ~lamport_request_args() throw() {}

  int32_t ts;
  int32_t wclient;

  _lamport_request_args__isset __isset;

  void __set_ts(const int32_t val) {
    ts = val;
  }

  void __set_wclient(const int32_t val) {
    wclient = val;
  }

  bool operator == (const lamport_request_args & rhs) const
  {
    if (!(ts == rhs.ts))
      return false;
    if (!(wclient == rhs.wclient))
      return false;
    return true;
  }
  bool operator != (const lamport_request_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_request_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_request_pargs {
 public:


  virtual ~lamport_request_pargs() throw() {}

  const int32_t* ts;
  const int32_t* wclient;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _lamport_request_result__isset {
  _lamport_request_result__isset() : success(false) {}
  bool success;
} _lamport_request_result__isset;

class lamport_request_result {
 public:

  lamport_request_result() : success(0) {
  }

  virtual ~lamport_request_result() throw() {}

  int32_t success;

  _lamport_request_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const lamport_request_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const lamport_request_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_request_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _lamport_request_presult__isset {
  _lamport_request_presult__isset() : success(false) {}
  bool success;
} _lamport_request_presult__isset;

class lamport_request_presult {
 public:


  virtual ~lamport_request_presult() throw() {}

  int32_t* success;

  _lamport_request_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _lamport_release_args__isset {
  _lamport_release_args__isset() : ts(false) {}
  bool ts;
} _lamport_release_args__isset;

class lamport_release_args {
 public:

  lamport_release_args() : ts(0) {
  }

  virtual ~lamport_release_args() throw() {}

  int32_t ts;

  _lamport_release_args__isset __isset;

  void __set_ts(const int32_t val) {
    ts = val;
  }

  bool operator == (const lamport_release_args & rhs) const
  {
    if (!(ts == rhs.ts))
      return false;
    return true;
  }
  bool operator != (const lamport_release_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_release_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_release_pargs {
 public:


  virtual ~lamport_release_pargs() throw() {}

  const int32_t* ts;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_release_result {
 public:

  lamport_release_result() {
  }

  virtual ~lamport_release_result() throw() {}


  bool operator == (const lamport_release_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const lamport_release_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_release_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_release_presult {
 public:


  virtual ~lamport_release_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class lamport_servercommunication_args {
 public:

  lamport_servercommunication_args() {
  }

  virtual ~lamport_servercommunication_args() throw() {}


  bool operator == (const lamport_servercommunication_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const lamport_servercommunication_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_servercommunication_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_servercommunication_pargs {
 public:


  virtual ~lamport_servercommunication_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_servercommunication_result {
 public:

  lamport_servercommunication_result() {
  }

  virtual ~lamport_servercommunication_result() throw() {}


  bool operator == (const lamport_servercommunication_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const lamport_servercommunication_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const lamport_servercommunication_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class lamport_servercommunication_presult {
 public:


  virtual ~lamport_servercommunication_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class lamportClient : virtual public lamportIf {
 public:
  lamportClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  lamportClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void lock();
  void send_lock();
  void recv_lock();
  void unlock();
  void send_unlock();
  void recv_unlock();
  int32_t request(const int32_t ts, const int32_t wclient);
  void send_request(const int32_t ts, const int32_t wclient);
  int32_t recv_request();
  void release(const int32_t ts);
  void send_release(const int32_t ts);
  void recv_release();
  void servercommunication();
  void send_servercommunication();
  void recv_servercommunication();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class lamportProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<lamportIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (lamportProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_lock(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_unlock(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_request(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_release(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_servercommunication(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  lamportProcessor(boost::shared_ptr<lamportIf> iface) :
    iface_(iface) {
    processMap_["lock"] = &lamportProcessor::process_lock;
    processMap_["unlock"] = &lamportProcessor::process_unlock;
    processMap_["request"] = &lamportProcessor::process_request;
    processMap_["release"] = &lamportProcessor::process_release;
    processMap_["servercommunication"] = &lamportProcessor::process_servercommunication;
  }

  virtual ~lamportProcessor() {}
};

class lamportProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  lamportProcessorFactory(const ::boost::shared_ptr< lamportIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< lamportIfFactory > handlerFactory_;
};

class lamportMultiface : virtual public lamportIf {
 public:
  lamportMultiface(std::vector<boost::shared_ptr<lamportIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~lamportMultiface() {}
 protected:
  std::vector<boost::shared_ptr<lamportIf> > ifaces_;
  lamportMultiface() {}
  void add(boost::shared_ptr<lamportIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void lock() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->lock();
    }
    ifaces_[i]->lock();
  }

  void unlock() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->unlock();
    }
    ifaces_[i]->unlock();
  }

  int32_t request(const int32_t ts, const int32_t wclient) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->request(ts, wclient);
    }
    return ifaces_[i]->request(ts, wclient);
  }

  void release(const int32_t ts) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->release(ts);
    }
    ifaces_[i]->release(ts);
  }

  void servercommunication() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->servercommunication();
    }
    ifaces_[i]->servercommunication();
  }

};

} // namespace

#endif