using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql.Data.MySqlClient;
using DbToolkit.App_Code;
using System.Data;

public partial class blog_manager : System.Web.UI.Page
{
    private DbUtils dbUtils = new DbUtils();
    private string sql = "";
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void add_now_Click(object sender, EventArgs e)
    {
        String cat = cate_name.Text;
        if(null != cat && "" != cat){
            sql = "INSERT INTO CATEGORY(CATEGORY_ID, CATEGORY_NAME) VALUES("+ dbUtils.get_CURRENT_USER_ID()+ ", '"+cat+" '  ）";
            dbUtils.CreateCommand(sql);        
            int res = dbUtils.getExecute();
            //Console.WriteLine("有" + res + "条记录受影响");
            //Response.Write("有" + res + "条记录受影响!");
            //username.Text = "";
            //password.Text = "";
            //re_password.Text = "";
            Response.Write(info.Text = "添加成功！");
            //Response.Redirect("default.aspx");
        }
    }
}