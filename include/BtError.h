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


#include <string>

class ErrorCatcher{
public:
	static enum error {
		FILE_FD_ERR,
		FILE_READ_ERR,
		INVALID_BTFILE_ERR,
		INVALID_SOCKET_ERR,
		INVALID_TRACKER_URL_ERR,
		INVALID_TRACKER_REPLY_ERR,
		INVALID_HASH_ERR,
		INVALID_MESSAGE_ERR,
		INVALID_PARAMETER_ERR,
		FAILED_ALLOCATE_MEM_ERR,
		NO_BUFFER_ERR,
		READ_SOCKET_ERR,
		WRITE_SOCKET_ERR,
		RECEIVE_EXIT_SIGNAL_ERR
	} ERROR;

public:
	static const std::string ErrorCatcher::

};
