<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <!-- Output settings -->
    <xsl:output method="html" indent="yes" />

    <!-- Root template -->
    <xsl:template match="/library">
        <html>
            <head>
                <title>Library Collection</title>
                <style>
                    body { font-family: Arial, sans-serif; margin: 20px; }
                    h1 { color: #2E8B57; }
                    h2 { color: #4682B4; margin-top: 20px; }
                    table { border-collapse: collapse; width: 100%; margin-top: 10px; }
                    th, td { border: 1px solid #ddd; padding: 8px; text-align: left; }
                    th { background-color: #f2f2f2; }
                </style>
            </head>
            <body>
                <h1>Library Collection</h1>

                <!-- Categories and Books -->
                <xsl:apply-templates select="categories" />

                <!-- Author Information -->
                <h2>Authors</h2>
                <table>
                    <tr>
                        <th>Author ID</th>
                        <th>Name</th>
                        <th>Nationality</th>
                    </tr>
                    <xsl:apply-templates select="authors/author" />
                </table>
            </body>
        </html>
    </xsl:template>

    <!-- Template for Categories -->
    <xsl:template match="categories">
        <h2>Category: <xsl:value-of select="name" /></h2>
        <table>
            <tr>
                <th>Book ID</th>
                <th>Title</th>
                <th>Author</th>
                <th>Publication Year</th>
                <th>Price (Currency)</th>
            </tr>
            <xsl:apply-templates select="books/book" />
        </table>
    </xsl:template>

    <!-- Template for Books -->
    <xsl:template match="book">
        <tr>
            <td><xsl:value-of select="@id" /></td>
            <td><xsl:value-of select="title" /></td>
            <!-- Fetch Author Name using IDREF -->
            <td>
                <xsl:value-of select="/library/authors/author[@id=current()/bookAuthor/@id]/authorName" />
            </td>
            <td><xsl:value-of select="publication/@year" /></td>
            <td><xsl:value-of select="price" /> (<xsl:value-of select="price/@currency" />)</td>
        </tr>
    </xsl:template>

    <!-- Template for Authors -->
    <xsl:template match="author">
        <tr>
            <td><xsl:value-of select="@id" /></td>
            <td><xsl:value-of select="authorName" /></td>
            <td><xsl:value-of select="nationality" /></td>
        </tr>
    </xsl:template>

</xsl:stylesheet>
