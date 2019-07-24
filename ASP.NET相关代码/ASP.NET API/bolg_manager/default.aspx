<%@ Page Title="" Language="C#" MasterPageFile="~/header.master" AutoEventWireup="true" CodeFile="default.aspx.cs" Inherits="_default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
    <style type="text/css">
        .auto-style3 {
            height: 24px;
        }
        .auto-style4 {
            width: 257px;
        }
        .left_menu li, .right_menu li {
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
        .left_menu, .right_menu {
            float:left;
        }
        .sider {
            height:100%;
            width:100%;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="header" Runat="Server">
    <div class="wrapper">
        <div class="article">
            <table style="width: 100%;">
                <tr>
                    <td class="auto-style4" rowspan="3">
                        <div class="sider">
                        </div>
                    </td>
                    <td class="auto-style3">
                        <asp:Label ID="title" runat="server" Text="标题"></asp:Label>
                    </td>
                </tr>
                <tr>
                    <td>
                        <asp:TextBox ID="subject" style="width:100%" runat="server" ></asp:TextBox>
                    </td>
                </tr>
                <tr>
                    <td>
                        <div class="menu">
                            <div class="left_menu">
                                <ul>
                                    <li class="default" title="文章管理"><a href="article_manage.aspx"><span class="">文章管理</span></a></li>
                                    <li class="default" title="分类管理"><a href="category_manage.aspx"><span class="">分类管理</span></a></li>
                                    <li class="default" title="评论管理"><a href="comment_manage.aspx"><span class="">评论管理</span></a></li>
                                </ul>
                            </div>
                            <div class="right_menu">
                                 <ul>
                                    <li class="default" title="文章管理"><a href="article_manage.aspx"><span class="">文章管理</span></a></li>
                                    <li class="default" title="分类管理"><a href="category_manage.aspx"><span class="">分类管理</span></a></li>
                                    <li class="default" title="评论管理"><a href="comment_manage.aspx"><span class="">评论管理</span></a></li>
                                </ul>
                            </div>
                        </div>
                    </td>
                </tr>
            </table>
            
        </div>
    </div>
</asp:Content>

