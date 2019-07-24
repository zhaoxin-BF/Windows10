using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Data;
using System.Data.SqlClient;

using System.Configuration;
using System.IO;

namespace DAL.Helper
{
    public class SQLHelper
    {
        private static string connString = "server=.;database=论坛系统数据库;uid=sa;pwd=123456";
        //private static string connString = ConfigurationManager.ConnectionStrings["connString"].ToString();

        #region 执行格式化SQL语句
        public static int Update(string sql)
        {
            SqlConnection conn = new SqlConnection(connString);
            SqlCommand cmd = new SqlCommand(sql, conn);

            try
            {
                conn.Open();
                return cmd.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                //将错误信息写入日志
                WriteLog("执行ublic static int Update(string sql)方法时发生异常：" + ex.Message);
                throw ex;
            }
            finally
            {
                conn.Close();
            }
        }

        public static object GetSingleResult(string sql)
        {
            SqlConnection conn = new SqlConnection(connString);
            SqlCommand cmd = new SqlCommand(sql, conn);

            try
            {
                conn.Open();
                return cmd.ExecuteScalar();
            }
            catch (Exception ex)
            {
                //将错误信息写入日志
                WriteLog("执行ublic static object GetSingleResult(string sql)方法时发生异常：" + ex.Message);
                throw ex;
            }
            finally
            {
                conn.Close();
            }
        }

        public static SqlDataReader GetReader(string sql)
        {
            SqlConnection conn = new SqlConnection(connString);
            SqlCommand cmd = new SqlCommand(sql, conn);

            try
            {
                conn.Open();
                return cmd.ExecuteReader(CommandBehavior.CloseConnection);
            }
            catch (Exception ex)
            {
                //将错误信息写入日志
                WriteLog("执行ublic static SqlDataReader GetReader(string sql)方法时发生异常：" + ex.Message);
                throw ex;
            }
        }

        #endregion

         #region 写入日志

        private static void WriteLog(string msg)
        {
            FileStream fs = new FileStream("progectlog.log", FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine(DateTime.Now.ToString() + "  " + msg);
            sw.Close();
            fs.Close();
        }

        #endregion
    }
}
