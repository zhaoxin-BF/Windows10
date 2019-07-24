using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SimpleAPI.Models
{
    public class UserInfo
    {
        public string LoginId { get; set; }
        public string LoginPwd { get; set; }
        public string LoginName { get; set; }

        public int LoginType { get; set; }

        internal void Add(UserInfo userInfo)
        {
            new NotImplementedException();
        }
    }
}