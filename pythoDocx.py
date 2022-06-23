## Irá buscar um texto dentro do arquivo word e substituir por outro texto
import docx

# Abre o arquivo
document = docx.Document('FOLHA DE PAGAMENTO.docx')
# Busca o texto
for paragraph in document.paragraphs:
    if '2000' in paragraph.text:
        # Substitui o texto
        paragraph.text = 'Deu certo, porra'
        # Salva o arquivo
        document.save('FOLHA DE PAGAMENTO.docx')
        break
    else:
        continue

