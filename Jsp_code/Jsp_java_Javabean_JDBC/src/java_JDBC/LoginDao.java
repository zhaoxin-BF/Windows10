package java_JDBC;
import java.sql.*;
import java.sql.SQLException;
import java_entity.Login;
public class LoginDao {
	public int Login(Login login){//1登录成功 0登录失败(用户名或系统异常) -1系统出现异常
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
		    
		    //c.创建Statement()
		    stmt = connection.createStatement();
		    
		    //String uname = request.getParameter("name");
		    //String upassword = request.getParameter("password");
		    
		    String sql = "select count(*) from student where sname='"+ login.getName() +"' and spasswd='"+login.getPwd()+"'";
			
			rs = stmt.executeQuery(sql);
			
			int count = 0;
			if(rs.next()) {
				count = rs.getInt(1);
			}
			if(count > 0) {
				return 1;//System.out.println("登录成功");
			}
			else {
				return 0;//System.out.println("登录失败");
			}
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
			return -1;
		} catch (SQLException e) {
			e.printStackTrace();
			return -1;
		} catch (Exception e) {
			e.printStackTrace();
			return -1;
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
	}
}
