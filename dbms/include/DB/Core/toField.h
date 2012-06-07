#pragma once

#include <Yandex/Common.h>		/// Yandex::VisitID_t

#include <DB/Core/Field.h>


namespace DB
{


/// Перевести что угодно в Field.
template <typename T>
inline Field toField(const T & x)
{
	return Field(typename NearestFieldType<T>::Type(x));
}

inline Field toField(const mysqlxx::Date & x)
{
	return toField(static_cast<UInt16>(x.getDayNum()));
}

inline Field toField(const mysqlxx::DateTime & x)
{
	return toField(static_cast<UInt32>(static_cast<time_t>(x)));
}

inline Field toField(const Yandex::VisitID_t & x)
{
	return toField(static_cast<UInt64>(x));
}

template <typename T>
inline Field toField(const mysqlxx::Null<T> & x)
{
	return x.isNull() ? Field(Null()) : toField(static_cast<const T &>(x));
}


}
