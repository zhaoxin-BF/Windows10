package com.Test;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//���ദ��login.html���ύ
public class LoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        String username=request.getParameter("username");
        String password=request.getParameter("password");
        PrintWriter out=response.getWriter();
        //1.���˺š�����ֱ�����Ϊroot��123
        if(username.equals("root")&&password.equals("123")){
            //2.����User���󱣴��˺š�����
            User user=new User();
            user.setUsername(username);
            user.setPassword(password);

            //3.����Session���󱣴�User����
            request.getSession().setAttribute("user", user);

            //4.��½�ɹ���תָ��ҳ��
            response.sendRedirect("/session_login/IndexServlet");
        }
        else{
            out.println("�˺Ż�����������������....");
        }
    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        doGet(request, response);
    }

}
