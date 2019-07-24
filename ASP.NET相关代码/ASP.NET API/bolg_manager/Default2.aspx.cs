using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MySql.Data.MySqlClient;


public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string conn = "Data Source=127.0.0.1;User ID=root;Password=;DataBase=blog_system";
        MySqlConnection con = new MySqlConnection(conn);
        con.Open();
        MySqlCommand cmd = new MySqlCommand("select * from user", con);
        MySqlDataReader dr = cmd.ExecuteReader();
        GridView1.DataSource = dr;
        GridView1.DataBind();
        dr.Close();
        con.Close();
    }
    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {
        
    }
}