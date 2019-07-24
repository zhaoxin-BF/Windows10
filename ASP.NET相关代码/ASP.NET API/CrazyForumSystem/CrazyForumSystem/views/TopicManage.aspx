<%@ Page Title="" Language="C#" MasterPageFile="~/Manange.Master" AutoEventWireup="true" CodeBehind="TopicManage.aspx.cs" Inherits="CrazyForumSystem.views.TopicManage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
        <style style="text/css">
            .container{
                width: 100%;
                height:500px;
                float:left;
                background:white;
                text-align:center;
            }
            .auto-style2 {
                font-size: x-large;
            }


        .detail_left ul li, .detail_right ul li {
            list-style:none;
            text-align: left;
            *zoom: 1;
            list-style: none;
            margin-right: 5px;
            padding: 5px;
            line-height: 100%;
            font: bold 16px "微软雅黑";
            font-style: normal;
            color: aqua;
            *float: none;
            *display: inline;
            display:inline-block;
        }
        .detail_left {
        float:left;
        width:50%;
        height:50px;
        padding:0;

        }
        .detail_right{
        float:right;
        width:50%;
        height:50px;
        padding:0;
        }
        .title, .subject {
            margin:10px auto;
            padding:5px;

        }
        .item {
            margin:20px auto;
            margin-left:200px;
            clear:both;
            padding:10px; 
            background-color:cornsilk;
        }
        .body {
            margin:0;
            padding:0;
            background-image:url(ban.jpg);
            background-attachment:fixed;
            background-repeat:repeat;
            font: bold 16px "微软雅黑";
        }

            .auto-style3 {
                width: 48%;
            }

    </style>
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <div class="container">
          <%--  一系列按钮控件--%>
            <table style="font-size:70%;width: 100%;">
                <tr style="table-layout:fixed;width:33.33%;">
                    <td class="auto-style2">论坛帖子管理</td>
                    <td><asp:TextBox ID="input" runat="server" Height="19px" Width="229px"></asp:TextBox></td>
                    <td style="text-align:left">
                        <asp:Button ID="btnsel" runat="server" Text="查询" Width="60px" OnClick="btnsel_Click" />
                        <asp:Button ID="btnupt" runat="server" Text="修改" Width="60px" OnClick="btnupt_Click" />
                        <asp:Button ID="btndel" runat="server" Text="删除" Width="60px" OnClick="btndel_Click" />
                        <asp:Button ID="btnadd" runat="server" Text="添加" Width="60px" OnClick="btnadd_Click" />
                    </td>
                </tr>
            </table>
            <div style="width:98%; margin:0 auto;">
                 <table style="100%">
                                        <thead>
                                            <tr>
                                                <th style="width: 10%;">序号</th>
                                                <th style="width: 30%">帖子名称</th>
                                                <th class="auto-style3">帖子简介</th>
                                                <th style="text-align: right;width:20%;"></th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                            <tr>
                                                <td>1</td>
                                                <td>Deshmukh</td>
                                                <td class="auto-style3">简介</td>
                                                <td>
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>2</td>
                                                <td>Deshmukh</td>
                                                <td class="auto-style3">简介</td>
                                                <td>
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>2</td>
                                                <td>Deshmukh</td>
                                                <td class="auto-style3">简介</td>
                                                <td>
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>2</td>
                                                <td>Deshmukh</td>
                                                <td class="auto-style3">简介</td>
                                                <td>
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>3</td>
                                                <td>Sanghani</td>
                                                <td class="auto-style3">简介</td>
                                                <td>
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                        </tbody>
                                    </table>
            </div>
            </div>
<%--            <div id="wrapper" runat="server" style="width:95%;background-color:aliceblue;align-items:center;margin:0 auto;">
        
            </div>--%>
        </div>
      

</asp:Content>
