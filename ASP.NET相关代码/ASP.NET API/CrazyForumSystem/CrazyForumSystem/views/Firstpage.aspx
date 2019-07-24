<%@ Page Title="" Language="C#" MasterPageFile="~/Home.Master" AutoEventWireup="true" CodeBehind="Firstpage.aspx.cs" Inherits="CrazyForumSystem.views.Firstpage" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style style="text/css">
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
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <div id="wrapper" runat="server" style="width:100%;background-color:aliceblue;align-items:center;margin:auto">
            <asp:DataList ID="dlTopic" runat="server">
                这是帖子的模板；
            </asp:DataList>
        </div>
        <div>
            <ul><il>标题：</il><il>简介：</il></ul>
            <ul>内容：</ul>
            <ul><il>发布者：</il><il>时间：</il></ul>
        </div>
</asp:Content>
