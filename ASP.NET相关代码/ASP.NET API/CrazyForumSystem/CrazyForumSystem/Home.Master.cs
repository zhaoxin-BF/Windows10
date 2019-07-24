using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CrazyForumSystem
{
    public partial class Home : System.Web.UI.MasterPage
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["CurrentUser"] != null)
            {
                welcome.Text = "欢迎您，" + Session["CurrentUser"].ToString();
            }
            else
            {
                welcome.Text = "欢迎您，游客";
            }
        }
    }
}