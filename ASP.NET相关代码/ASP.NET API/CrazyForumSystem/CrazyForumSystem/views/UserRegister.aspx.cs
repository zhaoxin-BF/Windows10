using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using DAL;
using Models;

namespace CrazyForumSystem.views
{
    public partial class UserRegister : System.Web.UI.Page
    {
        SysUsers objAdmin = new SysUsers();
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnRegister_Click(object sender, EventArgs e)
        {
            objAdmin.LoginId = this.texLoginId.Text.Trim();
            objAdmin.LoginName = this.texLoginName.Text.Trim();
            objAdmin.LoginPwd = this.texLoginPwd.Text.Trim();
            int Test = Convert.ToInt32(this.texTest.Text.Trim());
            if(objAdmin.LoginType == 1)
            {
                if(Test != 520)
                    this.ltaInfo.Text = "注册失败，请重新注册";
                else
                {
                    try
                    {
                        //objAdmin = new AdminService().AdminLogin(objAdmin);
                        int ret = new UserService().UserRegister(objAdmin);

                        if (ret == 1)
                        {
                            Response.Redirect("~/UserLogin.aspx");
                        }
                        else
                        {
                            this.ltaInfo.Text = "注册失败，请重新注册";
                        }
                    }
                    catch (Exception)
                    {
                        this.ltaInfo.Text = "发生异常！";
                    }
                }
            }
            else
            {
                if(Test != 520)
                {
                    try
                    {
                        //objAdmin = new AdminService().AdminLogin(objAdmin);
                        int ret = new UserService().UserRegister(objAdmin);

                        if (ret == 1)
                        {
                            Response.Redirect("~/UserLogin.aspx");
                        }
                        else
                        {

                            this.ltaInfo.Text = "注册失败，请重新注册";
                        }
                    }
                    catch (Exception)
                    {
                        this.ltaInfo.Text = "发生异常！";
                    }
                }
                else
                {
                    this.ltaInfo.Text = "注册失败，请重新注册";
                }

            }
            
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