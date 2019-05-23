package com.Test;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//此类处理login.html表单提交
public class LoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        String username=request.getParameter("username");
        String password=request.getParameter("password");
        PrintWriter out=response.getWriter();
        //1.把账号、密码分别设置为root、123
        if(username.equals("root")&&password.equals("123")){
            //2.创建User对象保存账号、密码
            User user=new User();
            user.setUsername(username);
            user.setPassword(password);

            //3.创建Session对象保存User对象
            request.getSession().setAttribute("user", user);

            //4.登陆成功跳转指定页面
            response.sendRedirect("/session_login/IndexServlet");
        }
        else{
            out.println("账号或密码错误，请从新输入....");
        }
    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        doGet(request, response);
    }

}
