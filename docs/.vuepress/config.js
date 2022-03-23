module.exports = {
  title: 'P3 Clicker',
  description: 'P3 Clicker module for GPD Pocket 3',
  plugins: [
    '@vuepress/active-header-links',
    '@vuepress/back-to-top',
    '@vuepress/last-updated',
    'vuepress-plugin-medium-zoom',
    'vuepress-plugin-smooth-scroll'
  ],
  head: [
    ['link', {rel: "shortcut icon", type: "image/png", sizes: "16x16", href: "/favicon.ico"}],
  ],
  markdown: {
    toc: {
      includeLevel:[1, 2, 3, 4]
    }
  }
}