all

# Don't enforce line length in code blocks
rule 'MD013', :code_blocks => false

# Allow duplicate titles
exclude_rule 'MD024'
# Allow titles to end in any punctuation
exclude_rule 'MD026'
# Allow inline HTML
exclude_rule 'MD033'
# Allow bare URL
exclude_rule 'MD034'
# Allow no alternate text in images
exclude_rule 'MD045'
