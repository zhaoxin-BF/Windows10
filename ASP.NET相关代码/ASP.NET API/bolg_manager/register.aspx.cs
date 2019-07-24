using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql.Data.MySqlClient;
using DbToolkit.App_Code;
using System.Data;

public partial class Default2 : System.Web.UI.Page

{
    private DbUtils dbUtils = new DbUtils();
    private string sql = "";
    protected void Page_Load(object sender, EventArgs e)
    {
        //Page.ClientScript.RegisterStartupScript(Page.GetType(), "", "document.getElementById('register').click();", true);

    }
    
    protected void register_Click(object sender, EventArgs e)
    {
        String pass = password.Text;
        String re_pass = re_password.Text;
        //定义USER_ID
        int userid = 4;
        if (pass != re_pass)
        {
            //Response.Write("输入密码不一致！");
            error.Text = "输入密码不一致！";
        }
        else {
            //Response.Write("密码一致！");
            //Response.Write(error.Text = "密码一致！");
            String name = username.Text;

            if (null != name && "" != name && null != pass && "" != pass && null != re_pass && "" != re_pass)
            {
                //定义SQL语句
                
                sql = "INSERT INTO USER(USER_ID, USER_NAME, PASSWORD) VALUES( "+userid+" , '" + name + "','" + pass + "')";
                dbUtils.CreateCommand(sql);
                //数据装载到Datatable中，只有一条密码。
                try
                {
                    int res = dbUtils.getExecute();
                }
                catch(Exception e) {
                    //Response.Write("用户名已存在！");
                    Console.WriteLine(e);
                    error.Text = "用户名已存在！";
                }
                
                //Console.WriteLine("有" + res + "条记录受影响");
                //Response.Write("有" + res + "条记录受影响!");
                //username.Text = "";
                //password.Text = "";
                //re_password.Text = "";
                error.Text = "注册成功！";

                //为注册用户分配资源。
                //分配文章分类表
                sql = "UPDATE USER_DATAILS SET CATEGORY_ID=" + userid + " WHERE USERID=" + userid + "";
                dbUtils.CreateCommand(sql);
                res = dbUtils.getExecute();
                Response.Write("分配文章分类表......");

                //分配留言表
                sql = "UPDATE USER_DATAILS SET MSGBOX_ID=" + userid + " WHERE USERID=" + userid + "";
                dbUtils.CreateCommand(sql);
                res = dbUtils.getExecute();
                Response.Write("分配留言箱......");



                //为下一位用户注册做准备。
                userid++;


                Response.Redirect("login.aspx");
               

                
                

                
            }
            else {
                //Response.Write("不能为空！");
                Response.Write(error.Text = "不能为空！");
            }
        }
    }
    protected void register_reset_button_Click(object sender, EventArgs e)
    {

    }
}