<%@ Page Title="" Language="C#" MasterPageFile="~/Manange.Master" AutoEventWireup="true" CodeBehind="NoticeManage.aspx.cs" Inherits="CrazyForumSystem.views.NoticeManage" %>

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
    </style>
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
        <div class="container">
          <%--  一系列按钮控件--%>
            <table style="font-size:70%;width: 100%;">
                <tr style="table-layout:fixed;width:33.33%;">
                    <td class="auto-style2">论坛公告管理</td>
                    <td><asp:TextBox ID="input" runat="server" Height="19px" Width="229px"></asp:TextBox></td>
                    <td style="text-align:left">
                        <asp:Button ID="btnsel" runat="server" Text="查询" Width="60px" OnClick="btnsel_Click" />
                        <asp:Button ID="btnupt" runat="server" Text="修改" Width="60px" OnClick="btnupt_Click" />
                        <asp:Button ID="btndel" runat="server" Text="删除" Width="60px" OnClick="btndel_Click" />
                        <asp:Button ID="btnadd" runat="server" Text="添加" Width="60px" OnClick="btnadd_Click" />
                    </td>
                </tr>
            </table>    
        </div>
</asp:Content>
