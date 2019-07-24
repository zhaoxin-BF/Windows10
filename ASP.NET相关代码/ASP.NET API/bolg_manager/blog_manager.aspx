<%@ Page Title="" Language="C#" MasterPageFile="~/header.master" AutoEventWireup="true" CodeFile="blog_manager.aspx.cs" Inherits="blog_manager" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
    <style type="text/css">
        .auto-style3 {
            width: 47px;
        }
        .sider ul li {
            
            text-align:center;
               *zoom:1; list-style: none;
             margin-right:5px;
                padding:5px;
               line-height:100%;
               font:bold 16px "微软雅黑";
               font-style:normal;
               color:aqua;
        }
        .details  li, .edit  li , .category_edit li {
            text-align:left;
               *zoom:1; list-style: none;
             margin-right:5px;
                padding:5px;
               line-height:100%;
               font:bold 16px "微软雅黑";
               font-style:normal;
               color:aqua;
               *float:none;
               *display:inline;
        
        }
        #category_item_title, .category_item {
            float:left;
        }
        .category_edit {
            float:right;
        }
          
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="header" Runat="Server">
    <div class="wrapper">
        <table style="width: 100%;">
            <tr>
                <td class="auto-style3">
                    <div class="sider" style="width:266px">
                        <ul style="">
                            <li class="default" title="文章管理"><a href="article_manage.aspx"><span class="">文章管理</span></a></li>
                            <li class="default" title="分类管理"><a href="category_manage.aspx"><span class="">分类管理</span></a></li>
                            <li class="default" title="评论管理"><a href="comment_manage.aspx"><span class="">评论管理</span></a></li>
                        </ul>
                    </div>
                </td>
                <td>
                    <div class="article_content" style="width:100%;" hidden="hidden">
                        <div class="article_item" style="width:100%; height:80px" >

                            <div class="title" >
                                <asp:Label ID="article_title" runat="server" Text="标题"></asp:Label>
                                <div style="float:left;">
                                 <ul style="" class="details">
                                    <li class="default" title="文章管理"><a href="article_manage.aspx"><span class="">
                                        <asp:Label ID="Label1" runat="server" Text="公开"></asp:Label></span></a></li>
                                    <li class="default" title="分类管理"><a href="category_manage.aspx"><span class="">分类管理</span></a></li>
                                    <li class="default" title="评论管理"><a href="comment_manage.aspx"><span class="">评论管理</span></a></li>
                                          </ul>
                                    </div>
                                <div style="float:right;">
                                <ul style="" class="edit">
                                    <li class="default" title="文章管理"><a href="article_manage.aspx"><span class="">文章管理</span></a></li>
                                    <li class="default" title="分类管理"><a href="category_manage.aspx"><span class="">分类管理</span></a></li>
                                    <li class="default" title="评论管理"><a href="comment_manage.aspx"><span class="">评论管理</span></a></li>
                                          </ul>
                                    </div> 

                            </div>

                        </div>
                    </div>

                    <div class="category_content" style="width:100%;" hidden="hidden">
                         <!--<input id="add_category" type="text" />-->
                        <asp:TextBox ID="cate_name" runat="server"></asp:TextBox>
                        <!--<input id="add_now" type="button" value="添加" />-->
                        <asp:Button ID="add_now" runat="server" Text="添加" OnClick="add_now_Click"  />
                        <div class="category_item" style="width:100%; height:80px" >
                           <asp:Label ID="category_item_title" runat="server" Text="分类标题" ></asp:Label>
                            <div class="category_edit_box">
                              <ul style="" class="category_edit">
                                    <li class="default" title="文章管理"><a href="article_manage.aspx"><span class="">置顶</span></a></li>
                                    <li class="default" title="分类管理"><a href="category_manage.aspx"><span class="">编辑</span></a></li>
                                    <li class="default" title="评论管理"><a href="comment_manage.aspx"><span class="">删除</span></a></li>
                                     </ul>

                            </div>


                            <div class="comment_content" style="width:100%;" hidden="hidden">
                        <div class="comment_item" style="width:100%; height:80px" >
                           <asp:Label ID="comment_item_content" runat="server" Text="评论内容" ></asp:Label>
                            <div class="category_edit_box">
                              <ul style="" class="category_edit">
                                    <li class="default" title="文章管理"><a href="article_manage.aspx"><span class="">置顶</span></a></li>
                                    <li class="default" title="分类管理"><a href="category_manage.aspx"><span class="">编辑</span></a></li>
                                    <li class="default" title="评论管理"><a href="comment_manage.aspx"><span class="">删除</span></a></li>
                                     </ul>

                            </div>

                        </div>
                    </div>
                         </div>
                         <asp:Label ID="info" runat="server" Text=""></asp:Label>
                </td>
            </tr>
            </table>
    </div>
</asp:Content>

