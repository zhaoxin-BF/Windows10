using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CrazyForumSystem.views
{
    public partial class TopicManage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {



            //if (0 != dt.Rows.Count)
            //{

                String HTML = "";

                //for (int i = 0; i < dt.Rows.Count; i++)
                //{
                //    String TITLE = dt.Rows[i][1] + "";
                //    DateTime PUBLISH_TIME = Convert.ToDateTime(dt.Rows[i][2]);
                //    String ARTICLE_CONTENT = dt.Rows[i][3] + "";



                //    String USER_NAME = dt.Rows[i][4] + "";
                //    String CATEGORY_NAME = dt.Rows[i][5] + "";
                //    int READ_COUNT = Convert.ToInt32(dt.Rows[i][6]);
                //    int ARTICLE_COMMENT_COUNT = Convert.ToInt32(dt.Rows[i][7]);


                //    //生成文章摘要
                //    int SUBJECT_LENGTH = 20;
                //    String SUBJECT = ARTICLE_CONTENT.Substring(0, SUBJECT_LENGTH);

                //    //Response.Write(TITLE + PUBLISH_TIME + ARTICLE_CONTENT + USER_NAME + CATEGORY_NAME + READ_COUNT + ARTICLE_COMMENT_COUNT);
                //    //处理一条数据记录

                    HTML += "<div class=\"item\"><table><tr><dr>";
                    HTML += "<div class=\"title\"><h3>标题:" + "TITLE" + "</h3></div></dr></tr>";
                    HTML += "<tr><dr><div class=\"subject\">摘要:" + "SUBJECT" + "</dr></tr>";
                    HTML += "<tr><dr>";
                    HTML += "<div class=\"detail_left\"> <ul><li>作者:" + "USER_NAME" + "</闪电><li>发布时间:" + "PUBLISH_TIME" + "</闪电><li>分类:" + "CATEGORY_NAME" + "</闪电></ul></div></dr>";
                    HTML += "<dr><div class=\"detail_right\"> <ul><li>阅读量:" + "READ_COUNT" + "</闪电><li>评论量:" + "ARTICLE_COMMENT_COUNT" + "</闪电></ul></div></dr></tr></table></div>";

                //}
                //wrapper.InnerHtml = HTML;


        }

        protected void btnsel_Click(object sender, EventArgs e)
        {

        }

        protected void btnupt_Click(object sender, EventArgs e)
        {

        }

        protected void btndel_Click(object sender, EventArgs e)
        {

        }

        protected void btnadd_Click(object sender, EventArgs e)
        {

        }
    }
}