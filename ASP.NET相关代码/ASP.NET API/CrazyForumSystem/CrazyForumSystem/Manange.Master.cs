using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CrazyForumSystem
{
    public partial class Manange : System.Web.UI.MasterPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                if (Session["CurrentUser"] != null)
                {
                    welcome.Text = "欢迎您管理员，" + Session["CurrentUser"].ToString();
                }
            }
        }
    }
}