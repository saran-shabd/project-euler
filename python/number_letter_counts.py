ones = ['', 'one', 'two', 'three', 'four',
        'five', 'six', 'seven', 'eight', 'nine']
tens = ['', 'ten', 'twenty', 'thirty', 'forty',
        'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
special_tens = ['', 'eleven', 'twelve', 'thirteen', 'fourteen',
                'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']


def number_letter_counts():

    total_count = 0

    for i in range(1000):
        digits = []
        while i > 0:
            digits.append(i % 10)
            i //= 10
        digits.reverse()

        output = []

        count = 0
        for i in range(len(digits)):
            zeros = len(digits) - 1 - i

            if 0 == zeros:
                count += len(ones[digits[i]])
                output.append(ones[digits[i]])
            if 1 == zeros:
                if digits[i] == 0:
                    continue
                if digits[i + 1] == 0:
                    count += len(tens[digits[i]])
                    output.append(tens[digits[i]])
                    break
                if digits[i] == 1:
                    count += len(special_tens[digits[i + 1]])
                    output.append(special_tens[digits[i + 1]])
                    break
                count += len(tens[digits[i]])
                count += len(ones[digits[i + 1]])
                output.append(tens[digits[i]])
                output.append(ones[digits[i + 1]])
                break
            if 2 == zeros:
                count += len(ones[digits[i]])
                count += len('hundred')
                output.append(ones[digits[i]])
                output.append('hundred')
                if 0 != digits[i+1] or 0 != digits[i+2]:
                    count += len('and')
                    output.append('and')

        print(" ".join(output))
        total_count += count

    return total_count


nums_total_len = number_letter_counts()
print('one thousand')
nums_total_len += len('one')
nums_total_len += len('thousand')
print('------------------------')
print(f'total count = {nums_total_len}')
print('------------------------')
