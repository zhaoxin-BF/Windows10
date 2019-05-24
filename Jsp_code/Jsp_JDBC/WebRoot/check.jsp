<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>检查登录</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <%   
		String URL="jdbc:mysql://localhost:3306/test";//数据库连接字符串
		String NAME="root";//
		String PASSWORD="123456";
		   
		Connection connection = null;
		Statement stmt = null;
		ResultSet rs = null;
		try{
		 	//a.导入驱动， 加载具体的驱动类
			Class.forName("com.mysql.jdbc.Driver");//加载数据库驱动，注册到驱动管理器
			
			//b.与数据库建立连接
		    connection = DriverManager.getConnection(URL,NAME,PASSWORD);
		    
		    stmt = connection.createStatement();
		    
		    String uname = request.getParameter("name");
		    String upassword = request.getParameter("password");
		    
		    String sql = "select count(*) from student where sname='"+ uname +"' and spasswd='"+upassword+"'";
			
			rs = stmt.executeQuery(sql);
			
			int count = 1;
			if(rs.next()) {
				count = rs.getInt(1);
			}
			if(count > 0) {
				response.getWriter().print("登录成功");
			}
			else {
				response.getWriter().print("注册失败");
				response.getWriter().print("请点击<a href='login.jsp'>返回登录界面</a>");
			}
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();	
		}
		finally {
			try {
				if(rs!=null) rs.close();
				if(stmt != null) stmt.close();
				if(connection != null) connection.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	%>    
  </body>
</html>
