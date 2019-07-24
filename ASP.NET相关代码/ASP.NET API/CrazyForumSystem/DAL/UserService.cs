using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Models;
using System.Data;
using System.Data.SqlClient;
using DAL.Helper;

namespace DAL
{
    public class UserService
    {
        public SysUsers UserLogin(SysUsers objAdmin)
        {
            string LoginId = objAdmin.LoginId;
            string LoginPwd = objAdmin.LoginPwd;
            int LoginType = objAdmin.LoginType;

            string sqlStr = "select LoginName from UserInfo where LoginId='" + LoginId + "' and LoginPwd='" + LoginPwd + "'and LoginType=" + LoginType + "";

            SqlDataReader sdr = SQLHelper.GetReader(sqlStr);

            if (sdr.Read())
            {
                objAdmin.LoginName = sdr["LoginName"].ToString();
            }
            else
            {
                objAdmin = null;
            }

            return objAdmin;
        }

        public int UserRegister(SysUsers objAdmin)
        {
            string LoginId = objAdmin.LoginId;
            string LoginPwd = objAdmin.LoginPwd;
            string LoginName = objAdmin.LoginName;
            
            int LoginType = objAdmin.LoginType;

            string sqlStr = "insert into UserInfo values('"+LoginId+"','"+LoginName+"','"+LoginPwd+"',"+LoginType+")";

            int sdr = SQLHelper.Update(sqlStr);
            if(sdr == 1)
            {
                return 1;
            }
            return 0;
        }
    }
}
