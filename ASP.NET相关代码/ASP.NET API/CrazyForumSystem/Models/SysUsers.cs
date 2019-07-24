using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Models
{
    public class SysUsers
    {
        /// <summary>
        /// 登录账户
        /// </summary>
        public string LoginId { get; set; }
        /// <summary>
        /// 登录密码
        /// </summary>
        public string LoginPwd { get; set; }
        /// <summary>
        /// 登录姓名
        /// </summary>
        public string LoginName { get; set; }

        public int LoginType { get; set; }
    }
}
