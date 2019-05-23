package day1;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
/**
 * 获得表单的数据（username,password）
 * 验证数据
 * 
 * @author 赵鑫5201314
 *
 */

public class LoginServlet extends HttpServlet{
	public void service(HttpServletRequest req,HttpServletResponse resp)
			throws ServletException, IOException {
		
		//规定代码格式
		resp.setContentType("text/jsp");
		resp.setCharacterEncoding("utf-8");
		req.setCharacterEncoding("utf-8");
		
		//获得表单的参数
		String username = req.getParameter("username");
		String password = req.getParameter("password");
		
		//获得相应的输出流
		PrintWriter pw = resp.getWriter();
		//验证
		if("zhaoxin".equals(username) && "123456".equals(password)){
			pw.println("<h1>登录成功</h1>");
		}else
			pw.println("<h1>登录失败</h1>");
	}
}
