using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DbToolkit.App_Code;
using System.Data;

public partial class _Default : System.Web.UI.Page
{
    private DbUtils dbUtils = new DbUtils();
    private string sql = "";
    protected void Page_Load(object sender, EventArgs e)
    {
        

    }
    protected void login_Click(object sender, EventArgs e)
    {
        //Response.Write(username.Text);
        String name = username.Text;
        String pass = password.Text;
        if (null != name && "" != name && null != pass && "" != pass) { 
            //定义SQL语句
            sql = "SELECT USER_ID, PASSWORD FROM USER WHERE USER_NAME =  '"+name+"' ";
            dbUtils.CreateCommand(sql);
            //数据装载到Datatable中，只有一条密码。
            DataTable dt = dbUtils.getSelect();
            //Response.Write(dt.Rows.Count);//返回1
            //Response.Write(dt.Rows[0][0]+ "");//返回1
            //Response.Write(dt.Rows[0][1] + "");
            //Response.Write(dt.Rows[0][2] + "");
            if (0 != dt.Rows.Count)
            {
                String real_id = dt.Rows[0][0] + "";
                String real_pass = dt.Rows[0][1] + "";
                //Response.Write(real_pass);

                if (real_pass == pass)
                {
                    Response.Redirect("default.aspx");
                    //准备用户身份
                   
                   
                    dbUtils.set_CURRENT_USER_ID (int.Parse( real_id));
                    
                }
                else
                {
                    //Response.Write("用户名或密码不正确！");
                    //Response.Write("<div><span>用户名或密码不正确！<span></div>");
                    error.Text = "用户名或密码不正确！";
                }
            }
            else {
                //Response.Write("用户名或密码不正确！");
                //Response.Write("<div><span>用户名或密码不正确！<span></div>");
                error.Text = "用户名或密码不正确！";
            }
        }
    }
    protected void login_reset_Click(object sender, EventArgs e)
    {
        Response.Write(error.Text = "请重新输入！");
    }
}