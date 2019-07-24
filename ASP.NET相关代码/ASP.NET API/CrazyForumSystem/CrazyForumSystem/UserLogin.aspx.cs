using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using DAL;
using Models;

namespace CrazyForumSystem
{
                
    public partial class UserLogin : System.Web.UI.Page
    {
        
        SysUsers objAdmin = new SysUsers();

        protected void Page_Load(object sender, EventArgs e)
        {
            Label name = (Label)Master.FindControl("welcome");
            name.Text = "欢迎您，游客";
        }

        protected void btnLogin_Click(object sender, EventArgs e)
        {

            objAdmin.LoginId = this.texLoginId.Text.Trim();
            objAdmin.LoginPwd = this.texLoginPwd.Text.Trim();

            try
            {
                //objAdmin = new AdminService().AdminLogin(objAdmin);
                objAdmin = new UserService().UserLogin(objAdmin);

                if (objAdmin == null)
                {
                    //this.ltaInfo.Text = "用户名身份或密码错误！";
                }
                else
                {
                    Session["CurrentUser"] = objAdmin.LoginName;
                    if(objAdmin.LoginType==1)
                    {
                        Response.Redirect("/views/TopicManage.aspx");
                    }
                    Response.Redirect("/views/Firstpage.aspx");
                }
            }
            catch (Exception)
            {
                this.ltaInfo.Text = "发生异常！";
            }
        }

        protected void btnRegister_Click(object sender, EventArgs e)
        {
            Response.Redirect("/views/UserRegister.aspx");
        }

        protected void rbt0_CheckedChanged(object sender, EventArgs e)
        {
            objAdmin.LoginType = 0;
        }

        protected void rbt1_CheckedChanged(object sender, EventArgs e)
        {
            objAdmin.LoginType = 1;
        }

    }
}