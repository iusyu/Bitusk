/*********************************
 * FileName: BtError.cpp
 *     Date: 2021-05-01 20:32
 *   Author: sunyi
 *  Version: 0.1
 *
 *   @brief: 错误处理模块 按照c++的OO设计来搞定。
 *
 ********************************
 */


#include "include/BtError.h"


inline
const std::string ErrorCatcher::fileFdError() {
	return "FILE_FD_ERR";
}


inline
const std::string ErrorCatcher::fileReadError() {
	return "FILE_READ_ERR";
}


inline
const std::string ErrorCatcher::fileWriteError() {
	return "INVALID_BTFILE_ERR";
}


inline
const std::string ErrorCatcher::invalidSocketError() {
	return "INVALID_SOCKET_ERR";
}


inline
const std::string ErrorCatcher::invalidTrackerUrlError() {
	return "INVALID_TRACKER_URL_ERR";
}


inline
const std::string ErrorCatcher::invalidTrackerReplyError() {
	return "INVALID_TRACKER_REPLY_ERR";
}


inline
const std::string ErrorCatcher::invalidHashError() {
	return "INVALID_HASH_ERR";
}


inline
const std::string ErrorCatcher::invalidMessageError() {
	return "INVALID_MESSAGE_ERR";
}


inline
const std::string ErrorCatcher::invalidParameterError() {
	return "INVALID_PARAMETER_ERR";
}


inline
const std::string ErrorCatcher::failedAllocateMemError() {
	return "FAILED_ALLOCATE_MEM_ERR";
}


inline
const std::string ErrorCatcher::noBufferError() {
	return "NO_BUFFER_ERR";
}


inline
const std::string ErrorCatcher::readSocketError() {
	return "READ_SOCKET_ERR";
}


inline
const std::string ErrorCatcher::writeSocketError() {
	return "WRITE_SOCKET_ERR";
}


inline
const std::string ErrorCatcher::receiveExitSignalError() {
	return "RECEIVE_EXIT_SIGNAL_ERR";
}
