package java_JDBC;
import java.sql.*;
import java.sql.SQLException;
import java_entity.Login;
public class LoginDao {
	public int Login(Login login){//1��¼�ɹ� 0��¼ʧ��(�û�����ϵͳ�쳣) -1ϵͳ�����쳣
		String URL="jdbc:mysql://localhost:3306/test";//���ݿ������ַ���
		String NAME="root";//
		String PASSWORD="123456";
		   
		Connection connection = null;
		Statement stmt = null;
		ResultSet rs = null;
		try{
		 	//a.���������� ���ؾ����������
			Class.forName("com.mysql.jdbc.Driver");//�������ݿ�������ע�ᵽ����������
			
			//b.�����ݿ⽨������
		    connection = DriverManager.getConnection(URL,NAME,PASSWORD);
		    
		    //c.����Statement()
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
				return 1;//System.out.println("��¼�ɹ�");
			}
			else {
				return 0;//System.out.println("��¼ʧ��");
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
