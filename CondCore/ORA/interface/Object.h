#ifndef INCLUDE_ORA_OBJECT_H
#define INCLUDE_ORA_OBJECT_H

#include <string>
//
#include <typeinfo>
#include <boost/shared_ptr.hpp>
// externals
#include "FWCore/Utilities/interface/TypeWithDict.h"

namespace ora {
  
  class Object {
    public:
    Object();
    Object( const void* ptr, const edm::TypeWithDict& type );
    Object( const Object& rhs);
    virtual ~Object();
    Object& operator=( const Object& rhs);
    bool operator==( const Object& rhs) const;
    bool operator!=( const Object& rhs) const;
    void* address() const;
    const edm::TypeWithDict& type() const;
    std::string typeName() const;
    void* cast( const std::type_info& asType ) const;
    template <typename T> T* cast() const;
    boost::shared_ptr<void> makeShared() const;
    void destruct();
    private:
    void* m_ptr;
    edm::TypeWithDict m_type;
  };
}

template <typename T>
inline
T* 
ora::Object::cast() const {
  const std::type_info& typeInfo = typeid(T);
  return static_cast<T*>( cast( typeInfo ) );
}

#endif

