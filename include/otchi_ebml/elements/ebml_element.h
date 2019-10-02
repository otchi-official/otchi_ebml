//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_H

// Abstract Base class for any ebml element.

#include <string>
#include <optional>
#include <otchi_ebml/types/ebml_path.h>

#include "otchi_ebml/elements/ebml_type.h"
#include "otchi_ebml/types/ebml_alias.h"

namespace otchi::ebml {

	///
	/// <summary>
	/// An Abstract Base Class for all Ebml Elements.
	/// </summary>
	/// <remarks>
	/// <para>
	///	You should almost never subclass this class directly, use one of the classes that implement the type already.
	///	So you don't have to implement the decoding yourself.
	///	</para>
	///	<para>
	///	If you do intend to subclass this abstract class directly you have to make sure to implement the mandatory fields,
	///	as well as the decoding mechanism.
	///	</para>
	///	<para>
	///	Every Ebml Element has 3 parts in its encoding.
	///	<list type="number">
	///		<item>
	///		<description>
	///		First comes a variable sized binary encoded integer value representing the ID of the element.
	///		It can be between 1 and 4 Bytes long.
	///		</description>
	///		</item>
	///		<item>
	///		<description>
	///		Second comes the data Size, another integer representing the size of its content. It can be a size between 1 and 8 Bytes.
	///		</description>
	///		</item>
	///		<item>
	///		<description>Lastly comes the actual content, its size is as large as the value of the data size in bytes.</description>
	///		</item>
	///	</list>
	///	</para>
	///	<para>
	///	We will refer from now on as the id size, the size required to represent an id.
	///	The data size, the size required to represent how large the content is.
	///	The content size, the actual size of the content.
	///	</para>
	/// </remarks>
	/// 
	class AbstractEbmlElement {

#pragma region Fields

		///
		/// <summary>
		/// The Size of the id, not to be confused with the id itself.
		/// This just tells how many octets are needed to represent the id.
		/// </summary>
		///
		ebml_size id_size_;
		
		///
		/// <summary>
		/// Similar to the id size, this value indicates how many octets are required to represent the value that indicates the content size.
		/// </summary>
		///
		ebml_size data_size_;
		
		///
		/// <summary>
		/// This value represents the actual size of the content of the element.
		/// </summary>
		///
		ebml_size content_size_;
		
		///
		/// <summary>
		/// The position of the first octet of the element.
		/// </summary>
		/// <remarks>
		/// This will always point to the position of the first octet of the id.
		/// </remarks>
		///
		ebml_position position_;
		
		///
		/// <summary>
		/// A weak reference to the parent element. It is null if the element is a root element.
		/// </summary>
		///
		std::weak_ptr<AbstractEbmlElement> parent_;

#pragma endregion

		// TODO: Parse path, should probably make path its own type with properties which values get set upon being set.

	public:

#pragma region Constructors
		
		AbstractEbmlElement(ebml_size id_size, ebml_size data_size, ebml_size data_content_size,
		                ebml_position position, std::weak_ptr<AbstractEbmlElement> parent = std::weak_ptr<AbstractEbmlElement>());

#pragma endregion

#pragma region getters

		///
		/// <summary>
		/// The size in octets of the entire element.
		/// </summary>
		/// <returns>The sum of the id size, the data size and the content size</returns>
		///
		[[nodiscard]] ebml_size get_element_size() const;

		///
		/// <value>Accessor to the size for the id.</value>
		///
		[[nodiscard]] ebml_size get_id_size() const;

		///
		/// <value>Accessor to the data size.</value>
		///
		[[nodiscard]] ebml_size get_data_size() const;

		///
		/// <value>Accessor to the size of the content.</value>
		///
		[[nodiscard]] ebml_size get_content_size() const;

		///
		/// <value>Accessor to the position of the first byte of the element in the file.</value>
		///
		[[nodiscard]] ebml_position get_position() const;

		///
		/// <value>Accessor to a weak reference to the parent of this element.</value>
		[[nodiscard]] std::weak_ptr<AbstractEbmlElement> get_parent() const;

		///
		/// <value>An optional value indicating how many times this element has to occur at least in its parent element.</value>
		///
		[[nodiscard]] std::optional<int> min_occurs() const;

		///
		/// <value>An optional value indicating how many times this element can occur maximally in its parent element.</value>
		/// 
		[[nodiscard]] std::optional<int> max_occurs() const;

#pragma endregion
		
#pragma region abstractMethods

		///
		/// <value>The type of this element.</value>
		/// <seealso cref="otchi_ebml::EBMLType">
		/// See the EBML Type for the available types.
		/// </seealso>
		/// 
		[[nodiscard]] virtual EbmlType get_type() const = 0;

		///
		/// <value>The name of the element.</value>
		/// 
		[[nodiscard]] virtual std::string get_name() const = 0;

		///
		/// <value>The ID of the element.</value>
		/// 
		[[nodiscard]] virtual ebml_id get_id() const = 0;

		///
		/// <value>The Path as specified by the EBML Specifications.</value>
		/// <seealso href="https://github.com/cellar-wg/ebml-specification/blob/master/specification.markdown#path">
		/// See the EBML Documentation for more Information.
		/// </seealso>
		/// 
		[[nodiscard]] virtual EbmlPath get_path() const = 0;

		///
		/// <summary>
		/// Decodes the current element at the position and with the size already defined.
		/// All Error Handling as well as Size checking have to be performed in the subclasses.
		/// </summary>
		/// <param name="ifstream">The stream to decode the element from.</param>
		///
		virtual void decode(std::ifstream& ifstream) = 0;

		// TODO ENCODE

#pragma endregion

#pragma region virtualMethods

		// TODO: Make useful :p
		[[nodiscard]] virtual bool validate_value() const;

		[[nodiscard]] virtual std::string get_description() const;

		virtual void print() const;

#pragma endregion

		// 
		virtual ~AbstractEbmlElement() = default;
		AbstractEbmlElement(const AbstractEbmlElement&) = delete;
		AbstractEbmlElement& operator =(AbstractEbmlElement const&) = delete;
		AbstractEbmlElement(AbstractEbmlElement&&) = delete;
		AbstractEbmlElement& operator=(AbstractEbmlElement&&) = delete;
	};

	template<const EbmlType type>
	class EbmlElement : AbstractEbmlElement {
		
		using AbstractEbmlElement::AbstractEbmlElement;

	public:
		virtual ~EbmlElement() = default;
		EbmlElement(const EbmlElement&) = delete;
		EbmlElement& operator =(EbmlElement const&) = delete;
		EbmlElement(EbmlElement&&) = delete;
		EbmlElement& operator=(EbmlElement&&) = delete;
	};
}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
