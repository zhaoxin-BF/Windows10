package com.Test;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
//1.创建IndexServlet显示网站的首界面 
public class IndexServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //2.response解决乱码问题
        response.setContentType("text/html;charset=utf-8");
        //3.创建Session对象保存用户信息
        HttpSession session=request.getSession();
        //4.方法体中的参数要与setAttribute()键一致
        User user=(User) session.getAttribute("user");
        if(user==null){
            response.getWriter().print("您还未登陆，请<a href='/session_login/login.html'>登陆</a>");
        }else{
            response.getWriter().print("您已登陆，欢迎您 "+user.getUsername());
            response.getWriter().print("<a href='/session_login/LogoutServlet'>退出</a>");

            //5.创建Cookie对象用来保存Session的id
            Cookie cookie=new Cookie("JSESSIONID",session.getId());
            cookie.setMaxAge(30*60);
            cookie.setPath("/session_login");
            response.addCookie(cookie);
        }


    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        doGet(request, response);
    }

}
