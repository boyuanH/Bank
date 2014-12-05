// ADOConn.h: interface for the CADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__27D0B44B_258B_4AE0_B715_83BA8B1883E8__INCLUDED_)
#define AFX_ADOCONN_H__27D0B44B_258B_4AE0_B715_83BA8B1883E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CADOConn  
{
	//添加成员变量
public:
	_RecordsetPtr m_pRecordset;//记录集指针
	_ConnectionPtr m_pConnection;//数据库连接指针

public:
	CADOConn();
	virtual ~CADOConn();
	void OnInitADOConn();//连接数据源
	_RecordsetPtr& GetRecordset(_bstr_t bstrSQL);//获取打开的记录集指针
	BOOL ExecuteSQL(_bstr_t bstrSQL);//执行sql语句
	void ExitConnect();//断开连接


};

#endif // !defined(AFX_ADOCONN_H__27D0B44B_258B_4AE0_B715_83BA8B1883E8__INCLUDED_)
