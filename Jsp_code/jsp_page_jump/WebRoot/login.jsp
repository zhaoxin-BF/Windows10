<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<center>
	<font color="green"><h1>用户登录系统</h1></font>
	<div>
		<form action="dologin.jsp" method="post">
			<span>用户名</span>
			<input type="text" name="username" />
			<br>
			<span>密码</span>
			<input type="text" name="password" />
			<br>
			<input type="submit" value="登录"/>
		</form>
	</div>
</center>

</body>
</html>