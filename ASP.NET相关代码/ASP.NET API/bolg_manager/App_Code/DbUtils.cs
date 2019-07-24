using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using MySql.Data.MySqlClient;
using System.Data;

/// <summary>
/// DbUtils 的摘要说明
/// </summary>
namespace DbToolkit.App_Code{
public  class DbUtils
{
	
		private MySqlConnection conn = null;
        private MySqlCommand cmd = null;
        private MySqlDataReader reader = null;

        //初始化用户的身份变量
        private static int CURRENT_USER_ID;


            public int get_CURRENT_USER_ID()
            {
                return CURRENT_USER_ID;
            }

             public void  set_CURRENT_USER_ID( int USER_ID)
            {
               DbUtils.CURRENT_USER_ID = USER_ID;
            }
        

        public DbUtils()

        {

            string connstr = "Data Source=10.29.11.238;User ID=admin;Password=admin;DataBase=blog_system;CharSet=utf8";

            conn = new MySqlConnection(connstr);
        }
 
        public void CreateCommand(string sql)
        {
            conn.Open();
            cmd = new MySqlCommand(sql, conn);
        }
 
        //插入,修改，删除数据方法
        public int getExecute()
        {
            int res = -1;
            try
            {
                res = cmd.ExecuteNonQuery();
            }catch(MySqlException ex)
            {
                Console.WriteLine("操作失败!" + ex.Message);
            }
            conn.Close();
            return res;
        }
 
        //查询数据
        public DataTable getSelect()
        {
            DataTable dt = new DataTable();
            using (reader = cmd.ExecuteReader(CommandBehavior.CloseConnection))
            {
                dt.Load(reader);
            }
            return dt;
        }
 
	}
}
