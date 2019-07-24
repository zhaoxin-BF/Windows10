using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using SimpleAPI.Models;

using System.Data.SqlClient;
using System.Data;
using Newtonsoft.Json;

namespace SimpleAPI.Controllers
{
    public class LoginController : ApiController
    {
        //Ilist<Beam> beamList = new List<Beam>();
        //beamList.Add(new Beam { Name="xxx", Age=18 });

        ///插入用户数据API
        //public bool Put(int id,UserInfo user)
        //{
        //    string sqlStr = "insert into UserInfo values('"+user.LoginId+"','"+user.LoginName+"','"+user.LoginPwd+"',"+user.LoginType+")";


        //    if(user != null)
        //    {
        //        int sdr = SQLHelper.Update(sqlStr);
        //        if(sdr == 1)
        //        {
        //            return true;
        //        }
        //        else
        //        {
        //            return false;
        //        }
        //    }
        //    return true;
        //}


        /// <summary>
        /// 返回用户信息API
        /// </summary>
        /// <param name="id"></param>
        /// <param name="user"></param>
        /// <returns></returns>
        public UserInfo Put2(int id, UserInfo user)
        {
            string sqlStr = "select * from UserInfo where LoginId='"+user.LoginId+"'and LoginPwd='"+user.LoginPwd+"'";

            SqlDataReader sdr = SQLHelper.GetReader(sqlStr);

            if(sdr.Read())
            {
                user.LoginName = sdr["LoginName"].ToString();
                user.LoginType = Convert.ToInt32(sdr["LoginType"]);
            }
            return user;
        }

        //返回所有用户信息API
        public IEnumerable<UserInfo> Get()
        {
            string loginId, loginPwd, loginName;
            int loginType;
            IList<UserInfo> userInfos = new List<UserInfo>();

            //创建要执行的sql语句
            string sqlStr = "select * from UserInfo";
            //执行语句
            SqlDataReader sdr = SQLHelper.GetReader(sqlStr);

            while(sdr.Read())
            {
                loginId = sdr["LoginId"].ToString();
                loginPwd = sdr["LoginPwd"].ToString();
                loginName = sdr["LoginName"].ToString();
                loginType = Convert.ToInt32(sdr["LoginType"]);
                userInfos.Add(new UserInfo() {LoginId=loginId, LoginPwd=loginPwd, LoginName=loginName, LoginType=loginType});
            }
            return userInfos;
        }

         //GET api/values/5
        //public string Get(string LoginId, string LoginPwd, int LoginType)

                                                                                                    //string result = "";
                                                                                                    //using (var client = new System.Net.Http.HttpClient())
                                                                                                    //{
                                                                                                    //    //通过客服端地址访问
                                                                                                    //    Uri bUrl = client.BaseAddress = new Uri(url);
                                                                                                    //    //序列化成json
                                                                                                    //    var requestJson = JsonConvert.SerializeObject(bUrl);
                                                                                                    //    //创建一个http 带正文和内容
                                                                                                    //    HttpContent httpContent = new StringContent(requestJson);
                                                                                                    //    //异步请求并将内容写入文件流中 返回字符串
                                                                                                    //    result = client.PostAsync("api/Product/AddProduct", httpContent).Result.Content.ReadAsStringAsync().Result;

                                                                                                    //}
        /// <summary>
        /// 判断用户登录信息是否正确
        /// </summary>
        /// <param name="LoginId"></param>
        /// <param name="LoginPwd"></param>
        /// <param name="LoginType"></param>
        /// <returns></returns>
        public bool Get(string LoginId,string LoginPwd,int LoginType)
        {
            try
            {
                string Loginid = LoginId;
                string Loginpwd = LoginPwd;
                int Logintype = LoginType;

                //创建要执行的sql语句
                string sqlStr = "select LoginName from UserInfo where LoginId='" + Loginid + "' and LoginPwd='" + Loginpwd + "' and LoginType=" + Logintype + "";
                //执行语句
                SqlDataReader sdr = SQLHelper.GetReader(sqlStr);

                if (sdr.Read())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            catch (Exception)
            {
                return false;
            }
        }

        //public static string Get(string url)
        //{
        //    string result = "";
        //    using (var client = new System.Net.Http.HttpClient())
        //    {
        //        //通过客服端地址访问
        //        Uri bUrl = client.BaseAddress = new Uri(url);
        //        //序列化成json
        //        var requestJson = JsonConvert.SerializeObject(bUrl);
        //        //创建一个http 带正文和内容
        //        HttpContent httpContent = new StringContent(requestJson);
        //        //异步请求并将内容写入文件流中 返回字符串
        //        result = client.PostAsync("api/Product/AddProduct", httpContent).Result.Content.ReadAsStringAsync().Result;

        //    }

        //    return result;
        //}
    }
}
