using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using WebAPIDemo.Models;

namespace WebAPIDemo.Controllers
{
    //webapi的控制器
    public class StudentsController : ApiController
    {
        //获取数据
        public List<Student> Get()
        {
            return new List<Student>()
            {
                new Student() {Id = 1,Name = "zhaoxin1"},
                new Student() {Id = 2,Name = "zhaoxin2"},
                new Student() {Id = 3,Name = "zhaoxin3"},
                new Student() {Id = 4,Name = "zhaoxin4"},
                new Student() {Id = 5,Name = "zhaoxin5"},
                new Student() {Id = 6,Name = "zhaoxin6"},
            };
        }

        
        public void Post(Student stu)
        {
            throw new Exception(message:"出错了");
        }

        //插入数据
        public void Put(int ID, Student stu)
        {

        }

        public void Delete(int id)
        {

        }
    }
}
