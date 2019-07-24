<%@ Page Title="" Language="C#" MasterPageFile="~/Main.Master" AutoEventWireup="true" CodeBehind="testLogin.aspx.cs" Inherits="CrazyForumSystem.testLogin" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style type="text/css">
        .auto-style1 {
            width: 14%;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div <%--style="color:white; font-weight:100;"--%>>
    <center>
        <p>&nbsp;</p>
        <p><h1>疯狂论坛登录</h1></p>

        <table style="border:dashed;auto">
            <thead>
					<tr >
						<th style="width:100px;float:right;"></th>
						<th style="width:150px;"></th>
						<th style="width:150px;"></th>
					</tr>
			</thead>
            <tbody  >
					<tr>
						<td style="float:right">用户名</td>
						<td><asp:TextBox ID="texLoginId" runat="server"></asp:TextBox></td>
						<td>&nbsp;</td>
					</tr>
					<tr>
						<td style="float:right">密码啊</td>
						<td><asp:TextBox ID="texLoginPwd" runat="server"></asp:TextBox></td>
						<td></td>
					</tr>
					<tr>
						<td></td>
						<td>&nbsp;&nbsp;&nbsp;&nbsp;
                            <asp:Button ID="btnLogin" runat="server" Text="登录"></asp:Button>
                            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                            <asp:Button ID="btnRegister" runat="server" Text="注册"></asp:Button>

						</td>
						<td></td>
					</tr>
				</tbody>
        </table>

        <br />


        <asp:Literal ID="ltaInfo" runat="server"></asp:Literal>
        <br />
    </center>
        <table class="table">
                                        <thead>
                                            <tr>
                                                <th style="width: 6%;">序号</th>
                                                <th style="width: 30%">帖子名称</th>
                                                <th>帖子简介</th>
                                                <th style="text-align: right;" class="auto-style1"></th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                            <tr>
                                                <td>1</td>
                                                <td>Deshmukh</td>
                                                <td>简介</td>
                                                <td class="auto-style1">
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>2</td>
                                                <td>Deshmukh</td>
                                                <td>简介</td>
                                                <td class="auto-style1">
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>2</td>
                                                <td>Deshmukh</td>
                                                <td>简介</td>
                                                <td class="auto-style1">
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>2</td>
                                                <td>Deshmukh</td>
                                                <td>简介</td>
                                                <td class="auto-style1">
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                            <tr>
                                                <td>3</td>
                                                <td>Sanghani</td>
                                                <td>简介</td>
                                                <td class="auto-style1">
                                                    <button class="btn">删除</button>
                                                    <button class="btn">查看</button>
                                                </td>
                                            </tr>
                                        </tbody>
                                    </table>
</div>
</asp:Content>
