package day1;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
/**
 * ��ñ������ݣ�username,password��
 * ��֤����
 * 
 * @author ����5201314
 *
 */

public class LoginServlet extends HttpServlet{
	public void service(HttpServletRequest req,HttpServletResponse resp)
			throws ServletException, IOException {
		
		//�涨�����ʽ
		resp.setContentType("text/jsp");
		resp.setCharacterEncoding("utf-8");
		req.setCharacterEncoding("utf-8");
		
		//��ñ��Ĳ���
		String username = req.getParameter("username");
		String password = req.getParameter("password");
		
		//�����Ӧ�������
		PrintWriter pw = resp.getWriter();
		//��֤
		if("zhaoxin".equals(username) && "123456".equals(password)){
			pw.println("<h1>��¼�ɹ�</h1>");
		}else
			pw.println("<h1>��¼ʧ��</h1>");
	}
}
